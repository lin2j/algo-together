/*
 * @lc app=leetcode.cn id=640 lang=c
 *
 * [640] 求解方程
 *
 * https://leetcode.cn/problems/solve-the-equation/description/
 *
 * algorithms
 * Medium (44.76%)
 * Likes:    201
 * Dislikes: 0
 * Total Accepted:    36.1K
 * Total Submissions: 80.8K
 * Testcase Example:  '"x+5-3+x=6+x-2"'
 *
 * 求解一个给定的方程，将x以字符串 "x=#value" 的形式返回。该方程仅包含 '+' ， '-' 操作，变量 x 和其对应系数。
 * 
 * 如果方程没有解或存在的解不为整数，请返回 "No solution" 。如果方程有无限解，则返回 “Infinite solutions” 。
 * 
 * 题目保证，如果方程中只有一个解，则 'x' 的值是一个整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: equation = "x+5-3+x=6+x-2"
 * 输出: "x=2"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: equation = "x=x"
 * 输出: "Infinite solutions"
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: equation = "2x=x"
 * 输出: "x=0"
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 3 <= equation.length <= 1000
 * equation 只有一个 '='. 
 * 方程由绝对值在 [0, 100]  范围内且无任何前导零的整数和变量 'x' 组成。​​​
 * 
 * 
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// @lc code=start

char * solveEquation(char *equation)
{
        int x_val = 0, right_val = 0;
        bool left = true;

        int idx = 0, n = strlen(equation);
        while (idx < n) {
                if (equation[idx] == '=') {
                        left = false;
                        idx++;
                }

                int sign = 1;
                if (equation[idx] == '-' || equation[idx] == '+') {
                        sign = equation[idx] == '-' ? -1 : 1;
                        idx++;
                }

                if (equation[idx] == 'x') {
                        sign = left ? sign : -1 * sign;
                        x_val = x_val + sign;
                        idx++;
                        continue;
                }

                int a = 0;
                while (idx < n && isdigit(equation[idx])) {
                        a = a * 10 + equation[idx] - '0';
                        idx++;
                }
                a = sign * a;

                if (equation[idx] == 'x') {
                        a = left ? a : -1 * a;
                        x_val = x_val + a;
                        idx++;
                        continue;
                }

                a = left ? -1 * a : a;
                right_val = right_val + a;
        }

        if (x_val == 0 && right_val == 0)
                return "Infinite solutions";

        if (x_val == 0 || right_val % x_val != 0) 
                return "No solution";


        char *result = malloc(sizeof(char) * 20);
        sprintf(result, "x=%d", right_val / x_val);

        return result;
}
// @lc code=end


