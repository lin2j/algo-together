/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 *
 * https://leetcode.cn/problems/plus-one/description/
 *
 * algorithms
 * Easy (45.44%)
 * Likes:    1177
 * Dislikes: 0
 * Total Accepted:    597K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = [1,2,3]
 * 输出：[1,2,4]
 * 解释：输入数组表示数字 123。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = [4,3,2,1]
 * 输出：[4,3,2,2]
 * 解释：输入数组表示数字 4321。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = [0]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */
#include <stdlib.h>
#include <string.h>

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * plusOne(int * digits, int digits_size, int *return_size)
{
        int c = 1;
        for (int i = digits_size - 1; i >= 0; i--) {
                if (c == 0) break;
                int a = digits[i] + c;
                digits[i] = a % 10;
                c = a / 10;
        }

        int *result = malloc(sizeof(int) * (digits_size + 1));
        int *p = result;
        *return_size = digits_size;
        if (c == 1) {
                (*return_size)++;
                result[0] = 1;
                p++;
        }
        memcpy(p, digits, sizeof(int) * digits_size);

        return result;
}
// @lc code=end


