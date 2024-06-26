/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (38.42%)
 * Total Accepted:    1.7M
 * Total Submissions: 4.5M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的 回文 子串。
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


// @lc code=start

static void expand_plindrome(char *s, int *l_ptr, int *r_ptr)
{
        int l = *l_ptr, r = *r_ptr;
        while (l >= 0 && s[r] != '\0' && s[l] == s[r]) {
                l--;
                r++;
        }
        *l_ptr = l + 1;
        *r_ptr = r - 1;
}


/*
 * 写一个方法，有两个指针 l 和 r 从指定位置向两边扩展，停止扩展的条件是
 * 1. l 或者 r 到达边界
 * 2. l 和 r 指向的元素不相等
 * 停止扩展之后，记录 l 和 r 的位置，如果比之前的子串长度大，则更新最新的
 * 子串的起止位置为 l 和 r
 *
 * (区间 [l, r] 的子串是回文子串)
 *
 */
char * longestPalindrome(char *s) 
{
        if (s == NULL || s[1] == '\0') return s;

        int max_l = 0, max_r = 0, max_len = 0;
        int l = 0, r = 0, new_len = 0;
        for (int i = 0; s[i] != '\0'; i++) {
                // 回文串长度是奇数的情况
                l = i, r = i;
                expand_plindrome(s, &l, &r);
                if ((new_len = r - l + 1) > max_len) {
                        max_l = l;
                        max_r = r;
                        max_len = new_len;
                }

                // 回文串长度是偶数的情况
                l = i, r = i + 1;
                expand_plindrome(s, &l, &r);
                if ((new_len = r - l + 1) > max_len) {
                        max_l = l;
                        max_r = r;
                        max_len = new_len;
                }
        }

        char *ans = malloc(sizeof(char) * max_len + 1);
        int k = 0;
        for (; max_l <= max_r; max_l++)
                ans[k++] = s[max_l];

        ans[k] = '\0';
        return ans;
}

// @lc code=end

