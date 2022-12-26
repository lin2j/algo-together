/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode.cn/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (65.72%)
 * Likes:    706
 * Dislikes: 0
 * Total Accepted:    532.6K
 * Total Submissions: 810.4K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "anagram", t = "nagaram" 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * s 和 t 仅包含小写字母
 * 
 * 
 * 
 * 
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// @lc code=start

int cmp(const void *_a, const void *_b) 
{
        char a = *(char *)_a, b = *(char *)_b;
        return a - b;
}

/**
 * 将 s 和 t 分别进行排序，如果是字母异位词，
 * 那么排序后的单词将是相同的
 */
bool isAnagram(char *s, char *t) 
{
        int len_s = strlen(s), len_t = strlen(t);
        if (len_s != len_t)
                return false;

        qsort(s, len_s, sizeof(char), cmp);
        qsort(t, len_t, sizeof(char), cmp);

        return strcmp(s, t) == 0;
}
// @lc code=end

