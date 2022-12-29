/*
 * @lc app=leetcode.cn id=628 lang=c
 *
 * [628] 三个数的最大乘积
 *
 * https://leetcode.cn/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (52.29%)
 * Likes:    419
 * Dislikes: 0
 * Total Accepted:    109.6K
 * Total Submissions: 209.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：6
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：24
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [-1,-2,-3]
 * 输出：-6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 
 * -1000 
 * 
 * 
 */
#include <stdint.h>
#include <stdlib.h>

// @lc code=start

#define MAX(a, b) (a) > (b) ? (a) : (b)

/*
 * 需要区分情况
 *   1. 若数组内全为非负数或者负数，那么答案为三个最大值的乘积
 *   2. 若数组内有正数有负数，则答案可能为三个最大值的乘积，或者是
 *       两个最小负数的乘积乘以最大值
 *
 * 使用五个变量，通过线性扫描得到三个最大值和两个最小值
 */
int maximumProduct(int *nums, int nums_size)
{
        int min1 = INT32_MAX, min2 = INT32_MAX;
        int max1 = INT32_MIN, max2 = INT32_MIN, max3 = INT32_MIN;

        for (int i = 0; i < nums_size; i++) {
                int x = nums[i];
                if (x > max1) {
                        max3 = max2;
                        max2 = max1;
                        max1 = x;
                } else if (x > max2) {
                        max3 = max2;
                        max2 = x;
                } else if (x > max3) {
                        max3 = x;
                }

                if (x < min1) {
                        min2 = min1;
                        min1 = x;
                } else if (x < min2) {
                        min2 = x;
                }
        }
        int c1 = min1 * min2 * max1;
        int c2 = max1 * max2 * max3;

        return MAX(c1, c2);

}
// @lc code=end


