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
#include <string.h>
#include <stdlib.h>

// @lc code=start

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void expand_from_center(char *s, int n, int *left, int *right) {
        while(*left >= 0 && *right < n) {
                if (s[*left] != s[*right])
                        return;

                if (s[*left] == s[*right]) {
                        (*left)--;
                        (*right)++;
                }
        }
}

/**
 * 遍历字符串 s，设 s 的长度为 n，索引为 i （1 ≤ i ≤ n-2)
 * 1. 以 i 为中心，向两边扩展，直到以 i 为中心的字符串不是回文串，返回长度
 * 2. 以 i, i+1 为中心，向两边扩展，直到以 i，i+1 为中心的字符串不是回文串，返回长度
 *
 * 注意：题目没有说，但从测试用例来看，b 和 B 是不相等的
 *
 * T(n): O(n2)
 * S(n): O(1)
 */
char * longestPalindrome(char *s)
{
        int n = strlen(s);

        if (n == 1) return s;

        // 记录最长回文串的起止位置
        // (max_start, max_end)
        int max_start = 0, max_end = 0;

        for (int i = 0; i < n - 1; i++) {
                int cur_len = max_end - max_start - 1;
                // 从 i 处扩展, (s1, e1)
                int s1 = i - 1, e1 = i + 1;
                expand_from_center(s, n, &s1, &e1);
                if (cur_len <= (e1 - s1 - 1)) {
                        max_start = s1;
                        max_end = e1;
                        cur_len = e1 - s1 - 1;
                }
                
                if (s[i] == s[i+1]) {
                        // i, i+1 处扩展 (s2, e2)
                        int s2 = i - 1, e2 = i + 2;
                        expand_from_center(s, n, &s2, &e2);
                        if (cur_len <= (e2 - s2 - 1)) {
                                max_start = s2;
                                max_end = e2;
                                cur_len = e2 - s2 - 1;
                        }
                }
        }

        int len = max_end - max_start;
        char *result = malloc(sizeof(char) * len);

        int k = 0;
        for (int i = max_start + 1; i < max_end; i++, k++)
                result[k] = s[i]; 

        result[k] = '\0';

        return result;
}




// @lc code=end


