/*
 * @lc app=leetcode.cn id=414 lang=c
 *
 * [414] 第三大的数
 *
 * https://leetcode.cn/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (39.69%)
 * Likes:    395
 * Dislikes: 0
 * Total Accepted:    129.5K
 * Total Submissions: 326.1K
 * Testcase Example:  '[3,2,1]'
 *
 * 给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[3, 2, 1]
 * 输出：1
 * 解释：第三大的数是 1 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：[1, 2]
 * 输出：2
 * 解释：第三大的数不存在, 所以返回最大的数 2 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：[2, 2, 3, 1]
 * 输出：1
 * 解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
 * 此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * 
 * 
 * 
 * 
 * 进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？
 * 
 */

#include <stdlib.h>

// @lc code=start

#define LONG_MIN_VALUE 0x8000000000000000L

/**
 * 使用 a,b,c 三个变量来分别存储前三大的数
 * 为了方便编程，将 a、b、c 设置为 long 型的最小值 LONG_MIN_VALUE
 * 遍历 nums，设当前遍历的数字为 x
 * 1. 若 x > a，则 a 不再是最大的数字，此时 c 替换为 b，b 替换为 a，a 替换为 x
 * 2. 若 a > x > b，则 b 不再是第二大的数字，此时 c 替换为 b，b 替换为 x
 * 3. 若 b > x > c，则 c 不在是第三大的数字，此时 c 替换为 x
 * 遍历结束之后，若 c 仍为 LONG_MIN_VALUE 则表示没有第三大的数字，返回 a
 *
 */
int thirdMax(int *nums, int nums_size)
{
        long a = LONG_MIN_VALUE;
        long b = LONG_MIN_VALUE;
        long c = LONG_MIN_VALUE;

        for (int i = 0; i < nums_size; i++) {
                int x = nums[i];
                if (x > a) {
                        c = b;
                        b = a;
                        a = x;
                } else if (x < a && x > b) {
                        c = b;
                        b = x;
                } else if (x < b && x > c) {
                        c = x;
                }
        }

        return c == LONG_MIN_VALUE ? a : c;
}
// @lc code=end


