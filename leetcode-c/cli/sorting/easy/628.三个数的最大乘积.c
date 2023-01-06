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
#include <stdlib.h>

// @lc code=start

#define MAX(a, b) (a) > (b) ? (a) : (b)

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/*
 * 1. 将 nums 从小到大排序
 * 2. 此时需要区分情况
 *   2.1 若数组内全为非负数或者负数，那么答案为三个最大值的乘积
 *   2.2 若数组内有正数有负数，则答案可能为三个最大值的乘积，或者是
 *       两个最小负数的乘积乘以最大值
 *
 */
int maximumProduct(int *nums, int nums_size)
{
        qsort(nums, nums_size, sizeof(int), cmp);
        
        int n = nums_size;
        int c1 = nums[0] * nums[1] * nums[n - 1];
        int c2 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        return MAX(c1, c2);
}
// @lc code=end


