/*
 * @lc app=leetcode.cn id=49 lang=c
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (67.80%)
 * Likes:    1376
 * Dislikes: 0
 * Total Accepted:    421.9K
 * Total Submissions: 622.1K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。
 * 可以按任意顺序返回结果列表。
 * 
 * 字母异位词 是由重新排列源单词的字母得到的一个新单词，
 * 所有源单词中的字母通常恰好只用一次。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * 示例 2:
 * 
 * 
 * 输入: strs = [""]
 * 输出: [[""]]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 * 
 * 
 */
#include <stdbool.h>
#include <stdlib.h>

// @lc code=start

bool isAnagram(char *s, char *t)
{
        int cnt[26] = {0};

        for (int i = 0; s[i] != '\0'; i++)
                cnt[s[i] - 'a']++;

        for (int i = 0; t[i] != '\0'; i++)
                cnt[t[i] - 'a']--;

        for (int i = 0; i < 26; i++)
                if (cnt[i] != 0) return false;

        return true;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char **strs, int strs_size, 
                       int *return_size, int **return_column_sizes)
{

}
// @lc code=end


