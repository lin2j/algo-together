/*
 * @lc app=leetcode.cn id=409 lang=c
 *
 * [409] 最长回文串
 *
 * https://leetcode.cn/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (55.76%)
 * Likes:    462
 * Dislikes: 0
 * Total Accepted:    145.4K
 * Total Submissions: 260.8K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。
 * 
 * 在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 
 * 
 * 示例 1: 
 * 
 * 
 * 输入:s = "abccccdd"
 * 输出:7
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:s = "a"
 * 输入:1
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 2000
 * s 只由小写 和/或 大写英文字母组成
 * 
 * 
 */
#include <string.h>

// @lc code=start

#define N 128

/*
 * there are two cases of the length of palindrome.
 *
 * if length is odd, every character's count in palindrome
 * are even, except the center one.
 *
 * if length is even, every character's count in palindrome
 * are even.
 *
 * so the longest palindrome is satisfied with one of 
 * the upon two cases. 
 *
 * just count every character of s and calculate
 * how many characters count are even, and choose
 * one of the odd count as the center character.
 */
int longestPalindrome(char *s)
{
        int map[N] = {0};
        int s_len = strlen(s);

        for(int i = 0; i < s_len; i++)
                map[s[i]]++;

        int res = 0, odd = 0;
        for(int i = 0; i < N; i++) {
                int count = map[i];
                int rem = count % 2;
                res += count - rem;
                if (rem == 1) odd = 1;
        }

        return res + odd;
}
// @lc code=end

