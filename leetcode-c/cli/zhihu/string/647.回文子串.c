/*
 * @lc app=leetcode.cn id=647 lang=c
 *
 * [647] 回文子串
 *
 * https://leetcode.cn/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (66.93%)
 * Likes:    1106
 * Dislikes: 0
 * Total Accepted:    258.3K
 * Total Submissions: 386.2K
 * Testcase Example:  '"abc"'
 *
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 * 
 * 回文字符串 是正着读和倒过来读一样的字符串。
 * 
 * 子字符串 是字符串中的由连续字符组成的一个序列。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 由小写英文字母组成
 * 
 * 
 */
#include <string.h>

// @lc code=start


int countSubstrings(char * s)
{
        int n = strlen(s);
        int ans = 0;

        for (int i = 0; i < n; i++) {
                // 模拟以一个字符为中心和以两个字符为中心的情况
                for (int j = 0; j <= 1; j++) {
                        int l = i;
                        int r = i + j;
                        while(l >= 0 && r <= n && s[l--] == s[r++])
                                ans++;
                }
        }

        return ans;
}
// @lc code=end


