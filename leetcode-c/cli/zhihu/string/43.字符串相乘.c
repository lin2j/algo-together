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

static inline int max(int a, int b)
{
        return a > b ? a: b;
}

static void reverse(char *l, char *r)
{
        char c;
        while (l < r) {
                c = *l;
                *l = *r;
                *r = c;
                l++;
                r--;
        }
}

static char * add_strings(char *num1, char *num2)
{
        int i = strlen(num1) - 1;
        int j = strlen(num2) - 1;

        char *res = malloc(sizeof(char) * (max(i, j) + 5));
        int k = 0, c = 0;
        while (i >= 0 || j >= 0 || c != 0) {
                if (i >= 0) c += num1[i] - '0';
                if (j >= 0) c += num2[j] - '0';
                res[k++] = c % 10 + '0';
                c /= 10;
                i--;
                j--;
        }

        reverse(res, res + k - 1);

        res[k] = '\0';
        return res;
}

char * multiply(char *num1, char *num2)
{
        int m = strlen(num1);
        int n = strlen(num2);

        char *ans = malloc(sizeof(char) * 2);
        ans[0] = '0', ans[1] = '\0';
        if (m == 1 && num1[0] == '0'|| n == 1 && num2[0] == '0')
                return ans;
                
        for (int i = n - 1; i >= 0; i--) {
                char *curr = malloc(sizeof(char) * (n + m + 5));
                int curr_len = 0;
                for (int j = n - 1; j > i; j--)
                        curr[curr_len++] = '0';

                int y = num2[i] - '0';
                int add = 0;
                for (int j = m - 1; j >= 0; j--) {
                        int x = num1[j] - '0';
                        int product = x * y + add;
                        curr[curr_len++] = product % 10 + '0';
                        add = product / 10;
                }
                while (add != 0) {
                        curr[curr_len++] = add % 10 + '0';
                        add /= 10;
                }

                reverse(curr, curr + curr_len - 1);

                curr[curr_len++] = '\0';
                char *tmp = add_strings(ans, curr);
                free(ans), free(curr);
                ans = tmp;
        }

        return ans;
}
// @lc code=end


