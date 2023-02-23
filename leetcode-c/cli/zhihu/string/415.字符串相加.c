/*
 * @lc app=leetcode.cn id=415 lang=c
 *
 * [415] 字符串相加
 *
 * https://leetcode.cn/problems/add-strings/description/
 *
 * algorithms
 * Easy (54.99%)
 * Likes:    675
 * Dislikes: 0
 * Total Accepted:    250.9K
 * Total Submissions: 456.5K
 * Testcase Example:  '"11"\n"123"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
 * 
 * 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：num1 = "11", num2 = "123"
 * 输出："134"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：num1 = "456", num2 = "77"
 * 输出："533"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：num1 = "0", num2 = "0"
 * 输出："0"
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num1.length, num2.length <= 10^4
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
 * 
 * 
 */
#include <stdlib.h>
#include <string.h>

// @lc code=start

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static void reverse(char *s, int len)
{
    for (int i = 0; i < len / 2; i++) {
        char t = s[i];
        s[i] = s[len - i - 1], s[len - i - 1] = t;
    }
}


char * addStrings(char *num1, char *num2)
{
        int len_1 = strlen(num1);
        int len_2 = strlen(num2);

        reverse(num1, len_1);
        reverse(num2, len_2);

        int c = 0;
        int n = MAX(len_1, len_2), len = 0;
        char *result = (malloc(sizeof(char) * (n + 2)));
        for (int i = 0, j = 0; i < n; i++, j++) {
                if (i < len_1) c += num1[i] - '0';
                if (j < len_2) c += num2[j] - '0';
                result[len++] = c % 10 + '0';
                c /= 10;
        }

        if (c == 1)
                result[len++] = '1';
        result[len] = '\0';
        reverse(result, len);

        return result;
}
// @lc code=end


