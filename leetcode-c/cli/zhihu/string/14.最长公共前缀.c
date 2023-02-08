/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 *
 * https://leetcode.cn/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (43.16%)
 * Likes:    2627
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.4M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 仅由小写英文字母组成
 * 
 * 
 */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// @lc code=start

#define MIN(a, b) ((a) > (b) ? (b) : (a))

/*
 * T(n): O(mn)
 * S(n0: O(1)
 */
char * longestCommonPrefix(char **strs, int strs_size)
{
        if (strs_size == 1)
                return strs[0];

        // [start, end)
        int start = 0;
        int end = INT32_MAX;

        for (int i = 0; i < strs_size - 1 && end > 0; i++) {
                int cp = 0;
                char *s1 = strs[i];
                char *s2 = strs[i + 1];
                while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
                        cp++;
                        s1++;
                        s2++;
                }

                end = MIN(end, cp);
        }

        int len = end - start;
        char *result = malloc(sizeof(char) * (len + 1));

        memcpy(result, strs[0], sizeof(char) * len);
        result[len] = '\0';

        return result;
}
// @lc code=end


