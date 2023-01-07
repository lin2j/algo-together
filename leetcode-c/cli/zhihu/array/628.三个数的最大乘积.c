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

// @lc code=start

/*
 * 三个数的乘积最大，有两种可能：
 * 1. 三个数都是最大的
 * 2. 两个最小的负数和一个最大的正数
 * 二者之中进行比较，取较大者即为答案
 */
int maximumProduct(int *nums, int nums_size)
{
        int max1 = INT32_MIN;
        int max2 = INT32_MIN;
        int max3 = INT32_MIN;
        int min1 = INT32_MAX;
        int min2 = INT32_MAX;

        for (int i = 0; i < nums_size; i++) {
                int n = nums[i];
                if (n > max1) {
                        max3 = max2;
                        max2 = max1;
                        max1 = n;
                } else if (n > max2) {
                        max3 = max2;
                        max2 = n;
                } else if (n > max3) {
                        max3 = n;
                }

                if (n < min1) {
                        min2 = min1;
                        min1 = n;
                } else if (n < min2) {
                        min2 = n;
                }
        }

        int c1 = max1 * max2 * max3;
        int c2 = max1 * min1 * min2;

        return c1 > c2 ? c1 : c2;
}
// @lc code=end


