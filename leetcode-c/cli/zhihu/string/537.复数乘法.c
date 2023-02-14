/*
 * @lc app=leetcode.cn id=537 lang=c
 *
 * [537] 复数乘法
 *
 * https://leetcode.cn/problems/complex-number-multiplication/description/
 *
 * algorithms
 * Medium (74.80%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    43.2K
 * Total Submissions: 57.7K
 * Testcase Example:  '"1+1i"\n"1+1i"'
 *
 * 复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件：
 * 
 * 
 * 实部 是一个整数，取值范围是 [-100, 100]
 * 虚部 也是一个整数，取值范围是 [-100, 100]
 * i^2 == -1
 * 
 * 
 * 给你两个字符串表示的复数 num1 和 num2 ，请你遵循复数表示形式，
 * 返回表示它们乘积的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：num1 = "1+1i", num2 = "1+1i"
 * 输出："0+2i"
 * 解释：(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：num1 = "1+-1i", num2 = "1+-1i"
 * 输出："0+-2i"
 * 解释：(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * num1 和 num2 都是有效的复数表示。
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// @lc code=start

static void parse_complex_number(char *num, int *real, int *image)
{
        char *token = strtok(num, "+");
        *real = atoi(token);
        token = strtok(NULL, "i");
        *image = atoi(token);
}

/* 
 * (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
 *
 */
char * complexNumberMultiply(char *num1, char *num2)
{
        int a = 0, b = 0;
        int c = 0, d = 0;

        parse_complex_number(num1, &a, &b);
        parse_complex_number(num2, &c, &d);

        char *result = malloc(sizeof(char) * 20);
        int real = a * c - b * d;
        int image = a * d + b * c;
        snprintf(result, 20, "%d+%di", real, image);

        return result;
}
// @lc code=end


