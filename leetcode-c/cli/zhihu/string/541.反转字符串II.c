/*
 * @lc app=leetcode.cn id=541 lang=c
 *
 * [541] 反转字符串 II
 *
 * https://leetcode.cn/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (58.72%)
 * Likes:    411
 * Dislikes: 0
 * Total Accepted:    170.6K
 * Total Submissions: 290.7K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，
 * 就反转这 2k 字符中的前 k 个字符。
 * 
 * 
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abcdefg", k = 2
 * 输出："bacdfeg"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abcd", k = 2
 * 输出："bacd"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由小写英文组成
 * 1 <= k <= 10^4
 * 
 * 
 */
#include <string.h>

// @lc code=start

static inline int min(int a, int b)
{
        return a > b ? b : a;
}

static void swap(char *a, char *b)
{
        char c = *a;
        *a = *b;
        *b = c;
}

static void reverse(char *l, char *r)
{
        while (l < r) swap(l++, --r);
}

/**
 * 1. 每隔 2k 翻转一次 [i, i + k)
 * 2. 当剩余的元素个数少于 2k 时，比较 i+k 和 n 的大小，取较小者
 */
char * reverseStr(char *s, int k)
{
        int n = strlen(s);

        for (int i = 0; i < n; i += 2 * k)
                reverse(&s[i], &s[min(i + k, n)]);

        return s;
}
// @lc code=end


