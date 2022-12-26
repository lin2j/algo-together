/*
 * @lc app=leetcode.cn id=268 lang=c
 *
 * [268] 丢失的数字
 *
 * https://leetcode.cn/problems/missing-number/description/
 *
 * algorithms
 * Easy (66.23%)
 * Likes:    672
 * Dislikes: 0
 * Total Accepted:    280.9K
 * Total Submissions: 424.1K
 * Testcase Example:  '[3,0,1]'
 *
 * 给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,0,1]
 * 输出：2
 * 解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1]
 * 输出：2
 * 解释：n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [9,6,4,2,3,5,7,0,1]
 * 输出：8
 * 解释：n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [0]
 * 输出：1
 * 解释：n = 1，因为有 1 个数字，所以所有的数字都在范围 [0,1] 内。1 是丢失的数字，因为它没有出现在 nums 中。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^4
 * 0 <= nums[i] <= n
 * nums 中的所有数字都 独一无二
 * 
 * 
 * 
 * 
 * 进阶：你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?
 * 
 */
#include <stdlib.h>

// @lc code=start

/**
 * 数学法：高斯求和公式
 * 利用数列求和的公式，求出 [0, n] 的和 total
 * 然后对数组进行求和 arr_sum，最终缺失的数字
 * 为 total - arr_sum
 */
int missingNumber(int *nums, int nums_size)
{
        int n = nums_size;
        int total = n * (n + 1) / 2;
        int arr_sum = 0;
        for (int i = 0; i < n; i++)
                arr_sum += nums[i];
        return total - arr_sum;
        
}
// @lc code=end


