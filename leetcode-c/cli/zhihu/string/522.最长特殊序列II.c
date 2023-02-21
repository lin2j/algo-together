/*
 * @lc app=leetcode.cn id=522 lang=c
 *
 * [522] 最长特殊序列 II
 *
 * https://leetcode.cn/problems/longest-uncommon-subsequence-ii/description/
 *
 * algorithms
 * Medium (48.86%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    31.2K
 * Total Submissions: 63.9K
 * Testcase Example:  '["aba","cdc","eae"]'
 *
 * 给定字符串列表 strs ，返回其中 最长的特殊序列 的长度。如果最长特殊序列不存在，返回 -1 。
 * 
 * 特殊序列 定义如下：该序列为某字符串 独有的子序列（即不能是其他字符串的子序列）。
 * 
 * s 的 子序列可以通过删去字符串 s 中的某些字符实现。
 * 
 * 
 * 例如，"abc" 是 "aebdc" 的子序列，因为您可以删除"aebdc"中的下划线字符来得到 "abc"
 * 。"aebdc"的子序列还包括"aebdc"、 "aeb" 和 "" (空字符串)。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: strs = ["aba","cdc","eae"]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: strs = ["aaa","aaa","aa"]
 * 输出: -1
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 2 <= strs.length <= 50
 * 1 <= strs[i].length <= 10
 * strs[i] 只包含小写英文字母
 * 
 * 
 */
#include <stdbool.h>
#include <string.h>

// @lc code=start

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 判断 s 是否是 t 的子序列
static bool is_sub(const char *s, const char *t)
{
        int i = 0, j = 0;
        int len_s = strlen(s);
        int len_t = strlen(t);

        while (i < len_s && j < len_t) {
                if (s[i] == t[j]) {
                        i++;
                }
                j++;
        }

        return i == len_s;
}

/*
 * 对于每个字符串 strs[i]，判断它是不是其他字符串
 * strs[j] (i != j) 的子序列，如果不是其他字符串
 * 的子序列，那么它的最长特殊子序列是其本身，记录
 * 它的长度，最后统计长度最大值即为答案
 */
int findLUSlength(char **strs, int strs_size)
{
        int ans = -1;
        for (int i = 0; i < strs_size; i++) {
                bool check = true;
                for (int j = 0; j < strs_size; j++) {
                        if (i != j && is_sub(strs[i], strs[j])) {
                                check = false;
                                break;
                        }
                }
                if (check) {
                        int len_s = (int) strlen(strs[i]);
                        ans = MAX(ans, len_s);
                }
        }

        return ans;
}
// @lc code=end


