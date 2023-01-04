/*
 * @lc app=leetcode.cn id=1859 lang=c
 *
 * [1859] 将句子排序
 *
 * https://leetcode.cn/problems/sorting-the-sentence/description/
 *
 * algorithms
 * Easy (73.81%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    13.6K
 * Total Submissions: 18.5K
 * Testcase Example:  '"is2 sentence4 This1 a3"'
 *
 * 一个 句子 指的是一个序列的单词用单个空格连接起来，
 * 且开头和结尾没有任何空格。每个单词都只包含小写或大写英文字母。
 * 
 * 我们可以给一个句子添加 从 1 开始的单词位置索引 ，
 * 并且将句子中所有单词 打乱顺序 。
 * 
 * 
 * 比方说，句子 "This is a sentence" 可以被打乱顺序得到 
 * "sentence4 a3 is2 This1" 或者 "is2 sentence4 This1 a3" 。
 * 
 * 
 * 给你一个 打乱顺序 的句子 s ，它包含的单词不超过 9 个，
 * 请你重新构造并得到原本顺序的句子。
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "is2 sentence4 This1 a3"
 * 输出："This is a sentence"
 * 解释：将 s 中的单词按照初始位置排序，得到 "This1 is2 a3 sentence4" ，然后删除数字。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "Myself2 Me1 I4 and3"
 * 输出："Me Myself and I"
 * 解释：将 s 中的单词按照初始位置排序，得到 "Me1 Myself2 and3 I4" ，然后删除数字。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * s 只包含小写和大写英文字母、空格以及从 1 到 9 的数字。
 * s 中单词数目为 1 到 9 个。
 * s 中的单词由单个空格分隔。
 * s 不包含任何前导或者后缀空格。
 * 
 * 
 */
#include <stdlib.h>
#include <string.h>

// @lc code=start

typedef struct {
        int     start, end; // 单词的范围为 [start, end)
        char    index;
        int     len;
} word;

static inline int cmp(const void *a, const void *b)
{
        word *wa = (word *)a;
        word *wb = (word *)b;

        return wa->index - wb->index;
}

/**
 * 定义结构体 word 记录单词在原字符串位置、单词长度和索引
 *
 * 1. 定义单词数组 words，将输入字符串按照空格分割
 * 2. 将遍历的单词数据存入 words 数组
 * 3. 将 words 数组按照索引升序排序
 * 4. 将 words 数组组成一个句子
 */
char * sortSentence(char *s)
{
        int len_s = 0, space_count = 0;
        char *p = s;
        while(*p != '\0') {
                if (*p++ == ' ') space_count++;
                len_s++;
        }

        // +1 是给 '\0' 留空间
        int len_new_s  = space_count + 1;
        int words_size = space_count + 1;

        word *words = malloc(sizeof(word) * words_size);
        int idx = 0;
        for (int i = 0; i < len_s; i++) {
                int start = i, end = i + 1;
                while(end < len_s && s[end] != ' ') end++;

                word w = {
                        .start    = start,
                        .end      = end - 1,  // end - 1 是数字
                        .len      = w.end - w.start,
                        .index    = s[w.end]
                };
                words[idx++] = w; 

                len_new_s += w.len;
                i = end;
        }

        qsort(words, words_size, sizeof(word), cmp);

        idx = 0;
        char *new_s = malloc(sizeof(char) * len_new_s);
        for (int i = 0; i < words_size; i++) {
                word w = words[i];
                memcpy(new_s + idx, s + w.start, sizeof(char) * w.len);

                idx += w.len;
                new_s[idx++] = ' ';
        }
        // 此时 new_s[idx - 1] 是一个多余的空格
        new_s[idx - 1] = '\0';

        return new_s;
}
// @lc code=end


