/*
 * @lc app=leetcode.cn id=412 lang=c
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.cn/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (69.44%)
 * Likes:    269
 * Dislikes: 0
 * Total Accepted:    177.3K
 * Total Submissions: 255.5K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，
 * 并用字符串数组 answer（下标从 1 开始）返回结果，其中：
 * 
 * 
 * answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
 * answer[i] == "Fizz" 如果 i 是 3 的倍数。
 * answer[i] == "Buzz" 如果 i 是 5 的倍数。
 * answer[i] == i （以字符串形式）如果上述条件全不满足。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["1","2","Fizz"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 5
 * 输出：["1","2","Fizz","4","Buzz"]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 15
 * 
 * 输出：["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// @lc code=start

char *FIZZ = "Fizz";
char *BUZZ = "Buzz";
char *FIZZ_BUZZ = "FizzBuzz";

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int *return_size)
{
        *return_size = n;
        char **result = malloc(sizeof(char *) * n);

        int k = 0;
        for (int i = 1; i <= n; i++) {
                bool t = i % 3 == 0;
                bool f = i % 5 == 0;

                if (t && f) {
                        result[k++] = FIZZ_BUZZ;
                } else if (t) {
                        result[k++] = FIZZ;
                } else if (f) {
                        result[k++] = BUZZ;
                } else {
                        result[k] = malloc(sizeof(char) * 6);
                        sprintf(result[k], "%d", i);
                        k++;
                }
        }

        return result;
}
// @lc code=end


