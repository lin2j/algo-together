/*
 * @lc app=leetcode.cn id=592 lang=c
 *
 * [592] 分数加减运算
 *
 * https://leetcode.cn/problems/fraction-addition-and-subtraction/description/
 *
 * algorithms
 * Medium (59.92%)
 * Likes:    132
 * Dislikes: 0
 * Total Accepted:    25.7K
 * Total Submissions: 42.8K
 * Testcase Example:  '"-1/2+1/2"'
 *
 * 给定一个表示分数加减运算的字符串 expression ，
 * 你需要返回一个字符串形式的计算结果。 
 * 
 * 这个结果应该是不可约分的分数，即最简分数。 如果最终结果是一个整数，
 * 例如 2，你需要将它转换成分数形式，其分母为 1。所以在上述例子中, 2
 * 应该被转换为 2/1。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: expression = "-1/2+1/2"
 * 输出: "0/1"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: expression = "-1/2+1/2+1/3"
 * 输出: "1/3"
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: expression = "1/3-1/2"
 * 输出: "-1/6"
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 输入和输出字符串只包含 '0' 到 '9' 的数字，以及 '/', '+' 和 '-'。 
 * 输入和输出分数格式均为 ±分子/分母。如果输入的第一个分数或者输出的分数是正数，则 '+' 会被省略掉。
 * 输入只包含合法的最简分数，每个分数的分子与分母的范围是  [1,10]。 如果分母是1，意味着这个分数实际上是一个整数。
 * 输入的分数个数范围是 [1,10]。
 * 最终结果的分子与分母保证是 32 位整数范围内的有效整数。
 * 
 * 
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// @lc code=start

#define MAX_STR_LEN 80

long long gcd(long long a, long long b) 
{
        long remainder = a % b;
        while (remainder != 0) {
                a = b;
                b = remainder;
                remainder = a % b;
        }
        return b;
}

/*
 * 把分母弄成一样，分子求和，然后再根据
 * 分子和与分母的最大公约数进行约分
 */
char * fractionAddition(char *expression)
{
        long long x = 0, y = 1;
        int idx = 0, n = strlen(expression);

        while(idx < n) {
                // 读取分子
                long long x1 = 0;
                int sign = 1;
                if (expression[idx] == '-' || expression[idx] == '+') {
                        sign = expression[idx] == '-' ? -1 : 1;
                        idx++;
                }
                while (idx < n && isdigit(expression[idx])) {
                        x1 = x1 * 10 + expression[idx] - '0';
                        idx++;
                }
                x1 = x1 * sign;
                idx++;

                // 读取分母
                long long y1 = 0;
                while (idx < n && isdigit(expression[idx])) {
                        y1 = y1 * 10 + expression[idx] - '0';
                        idx++;
                }

                x = x * y1 + x1 * y;
                y = y * y1;
        }

        if (x == 0) {
                return "0/1";
        }

        long long g = gcd(llabs(x), y);
        char *result = malloc(sizeof(char) * MAX_STR_LEN);
        sprintf(result, "%lld/%lld", x / g, y / g);

        return result;
}
// @lc code=end


