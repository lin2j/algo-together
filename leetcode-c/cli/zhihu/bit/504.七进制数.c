/*
 * @lc app=leetcode.cn id=504 lang=c
 *
 * [504] 七进制数
 *
 * https://leetcode.cn/problems/base-7/description/
 *
 * algorithms
 * Easy (51.88%)
 * Likes:    200
 * Dislikes: 0
 * Total Accepted:    84.8K
 * Total Submissions: 163.5K
 * Testcase Example:  '100'
 *
 * 给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: num = 100
 * 输出: "202"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: num = -7
 * 输出: "-10"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -10^7 <= num <= 10^7
 * 
 * 
 */
#include <stdbool.h>
#include <stdlib.h>

// @lc code=start

#define MAX_STR_LEN 20

static void reverse(char *l, char *r)
{
        char c;
        while(l < r) {
               c = *l;
               *l = *r;
               *r = c;

               l++;
               r--;
        }
}

char * convertToBase7(int num)
{
        if (num == 0)
                return "0";

        bool negative = false;
        int idx = 0;
        char *result = malloc(sizeof(char) * MAX_STR_LEN);
        if (num < 0) {
                negative = true;
                num = -num;
        }
        while(num != 0) {
                result[idx++] = num % 7 + '0';
                num /= 7;
        }
        if (negative) result[idx++] = '-';
        reverse(result, result + idx - 1);
        result[idx] = '\0';

        return result;
}
// @lc code=end


