/*
 * @lc app=leetcode.cn id=2273 lang=c
 *
 * [2273] 移除字母异位词后的结果数组
 *
 * https://leetcode.cn/problems/find-resultant-array-after-removing-anagrams/description/
 *
 * algorithms
 * Easy (59.39%)
 * Likes:    21
 * Dislikes: 0
 * Total Accepted:    10.9K
 * Total Submissions: 18.3K
 * Testcase Example:  '["abba","baba","bbaa","cd","cd"]'
 *
 * 给你一个下标从 0 开始的字符串 words ，其中 words[i] 由小写英文字符组成。
 * 
 * 在一步操作中，需要选出任一下标 i ，从 words 中 删除 words[i] 。其中下标
 * i 需要同时满足下述两个条件：
 * 
 * 
 * 0 < i < words.length
 * words[i - 1] 和 words[i] 是 字母异位词 。
 * 
 * 
 * 只要可以选出满足条件的下标，就一直执行这个操作。
 * 
 * 在执行所有操作后，返回 words 。可以证明，按任意顺序为每步操作选择下标都
 * 会得到相同的结果。
 * 
 * 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母
 * 通常恰好只用一次。例如，"dacb" 是 "abdc" 的一个字母异位词。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：words = ["abba","baba","bbaa","cd","cd"]
 * 输出：["abba","cd"]
 * 解释：
 * 获取结果数组的方法之一是执行下述步骤：
 * - 由于 words[2] = "bbaa" 和 words[1] = "baba" 是字母异位词，选择下标 2 并删除 words[2] 。
 * ⁠ 现在 words = ["abba","baba","cd","cd"] 。
 * - 由于 words[1] = "baba" 和 words[0] = "abba" 是字母异位词，选择下标 1 并删除 words[1] 。
 * ⁠ 现在 words = ["abba","cd","cd"] 。
 * - 由于 words[2] = "cd" 和 words[1] = "cd" 是字母异位词，选择下标 2 并删除 words[2] 。
 * ⁠ 现在 words = ["abba","cd"] 。
 * 无法再执行任何操作，所以 ["abba","cd"] 是最终答案。
 * 
 * 示例 2：
 * 
 * 输入：words = ["a","b","c","d","e"]
 * 输出：["a","b","c","d","e"]
 * 解释：
 * words 中不存在互为字母异位词的两个相邻字符串，所以无需执行任何操作。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 10
 * words[i] 由小写英文字母组成
 * 
 * 
 */
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// @lc code=start

bool is_anagram(char *s, char *t) 
{
        // 使用 char 类型会无法通过测试用例
        int count_map[26] = {0};

        while(*s != '\0' && *t != '\0') {
                count_map[*s++ - 'a']++;
                count_map[*t++ - 'a']--;
        }

        if (*s != '\0' || *t != '\0')
                return false;

        for (int i = 0; i < 26; i++) {
                if (count_map[i] != 0)
                        return false;
        }

        return true;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** removeAnagrams(char **words, int words_size, int *return_size)
{
        *return_size = 0;
        char **result = malloc(sizeof(char *) * words_size);
        for (int i = 0; i < words_size;) {
                int j = i + 1;
                while(j < words_size && is_anagram(words[i], words[j])) {
                        j++;
                }
                result[(*return_size)++] = words[i];
                i = j;
        }
        return result;
}
// @lc code=end


