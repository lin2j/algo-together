/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.11%)
 * Likes:    5695
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 3.2M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// @lc code=start

#define MAX(x, y) ((x) > (y) ? (x) : (y))

/*
 * expand on position i, s[i] as the center of palindrome.
 * if the length of palindrome is even, i is equals j at the
 * start, or i is equals j+1.
 *
 * return: the length of palindrome
 *
 */
int expand_around_center(char *s, int s_len, int i, int j)
{
        while(i >= 0 && j < s_len && s[i] == s[j]) {
                i--;
                j++;
        }
        return j - i - 1;
}

char * longestPalindrome(char *s)
{
        int start = 0, end = 0;
        int s_len = strlen(s);

        for(int i = 0; i < s_len; i++) {
                int len1 = expand_around_center(s, s_len, i, i);
                int len2 = expand_around_center(s, s_len, i, i + 1);

                int len = MAX(len1, len2);
                if (len > end - start) {
                        start = i - (len - 1) / 2;
                        end = i + len / 2;
                }
        }

        int len = end - start + 2;
        char *ret = (char *)malloc(sizeof(char) * len);
        memcpy(ret, s + start, len);

        ret[len - 1] = '\0';

        return ret;
}
// @lc code=end

