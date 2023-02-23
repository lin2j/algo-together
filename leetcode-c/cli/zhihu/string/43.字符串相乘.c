/*
 * @lc app=leetcode.cn id=43 lang=c
 *
 * [43] 字符串相乘
 *
 * https://leetcode.cn/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.67%)
 * Likes:    1153
 * Dislikes: 0
 * Total Accepted:    283K
 * Total Submissions: 633.8K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num1.length, num2.length <= 200
 * num1 和 num2 只能由数字组成。
 * num1 和 num2 都不包含任何前导零，除了数字0本身。
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// @lc code=start

#define MAX_STR_LEN 40000 

char * multiply(char *num1, char *num2)
{
        int len_1 = strlen(num1);
        int len_2 = strlen(num2);

        int k = 1;
        long long mul = 0;
        for (int i = len_1 - 1; i >= 0; i--) {
                long long m = 0, c = 1;
                int a = num1[i] - '0';
                for (int j = len_2 - 1; j >= 0; j--) {
                        int b = num2[j] - '0';
                        m = m + a * b * c;
                        c *= 10;
                }
                mul = mul + m * k;
                k *= 10;
        }

        char *result = malloc(sizeof(char) * MAX_STR_LEN);
        sprintf(result, "%lld", mul);

        return result;
}
// @lc code=end


