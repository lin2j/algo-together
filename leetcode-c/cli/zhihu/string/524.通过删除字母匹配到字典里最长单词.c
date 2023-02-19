/*
 * @lc app=leetcode.cn id=524 lang=c
 *
 * [524] 通过删除字母匹配到字典里最长单词
 *
 * https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (50.04%)
 * Likes:    325
 * Dislikes: 0
 * Total Accepted:    97.1K
 * Total Submissions: 193.8K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s
 * 中的某些字符得到。
 * 
 * 如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 * 输出："apple"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abpcplea", dictionary = ["a","b","c"]
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 1000
 * s 和 dictionary[i] 仅由小写英文字母组成
 * 
 * 
 */
#include <stdbool.h>
#include <stdlib.h>

// @lc code=start

bool is_subsequence(char *s, char *t, int *l)
{
        int i = 0, j = 0;
        while (s[i] != '\0' && t[j] != '\0') {
                if (s[i] == t[j]) {
                        i++;
                        j++;
                        continue;
                }
                j++;
        }

        *l = i;
        return s[i] == '\0';

}

char * findLongestWord(char * s, char ** dictionary, int dictionary_size)
{
        int max = -1;
        char *result = "";

        for (int i = 0; i < dictionary_size; i++) {
                int l = 0;
                bool sub = is_subsequence(dictionary[i], s, &l);
                if (sub && l > max) {
                        max = l;
                        result = dictionary[i];
                }
        }

        return result;
}
// @lc code=end


