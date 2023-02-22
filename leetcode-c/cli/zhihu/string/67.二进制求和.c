/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 *
 * https://leetcode.cn/problems/add-binary/description/
 *
 * algorithms
 * Easy (53.38%)
 * Likes:    963
 * Dislikes: 0
 * Total Accepted:    304.3K
 * Total Submissions: 570.5K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入:a = "11", b = "1"
 * 输出："100"
 * 
 * 示例 2：
 * 
 * 
 * 输入：a = "1010", b = "1011"
 * 输出："10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= a.length, b.length <= 10^4
 * a 和 b 仅由字符 '0' 或 '1' 组成
 * 字符串如果不是 "0" ，就不含前导零
 * 
 * 
 */
#include <string.h>
#include <stdlib.h>

// @lc code=start
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static void reverse(char *s, int len)
{
    for (int i = 0; i < len / 2; i++) {
        char t = s[i];
        s[i] = s[len - i - 1], s[len - i - 1] = t;
    }
}

char * addBinary(char *a, char *b)
{
        int len_a = strlen(a);
        int len_b = strlen(b);

        reverse(a, len_a);
        reverse(b, len_b);

        int carry = 0;
        int n = MAX(len_a, len_b), len = 0;
        char *result = malloc(sizeof(char) * (n + 2));
        for (int i = 0; i < n; i++) {
                if (i < len_a) carry += a[i] - '0';
                if (i < len_b) carry += b[i] - '0';
                result[len++] = carry % 2 + '0';
                carry /= 2;
        }

        if (carry == 1)
                result[len++] = '1';
        
        result[len] = '\0';
        reverse(result, len);

        return result;
}
// @lc code=end


