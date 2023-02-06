/*
 * @lc app=leetcode.cn id=238 lang=c
 *
 * [238] 除自身以外数组的乘积
 *
 * https://leetcode.cn/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (74.44%)
 * Likes:    1351
 * Dislikes: 0
 * Total Accepted:    243.3K
 * Total Submissions: 327K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
 * 
 * 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
 * 
 * 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,3,4]
 * 输出: [24,12,8,6]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [-1,1,0,-3,3]
 * 输出: [0,0,9,0,0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内
 * 
 * 
 * 
 * 
 * 进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 * 
 */
#include <stdlib.h>

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 使用两个数组，分别计算 i 的左边乘积和右边乘积
 * 数组 L 计算 [0, i - 1] 的乘积
 * 数组 R 计算 [i + 1, n - 1] 的乘积
 *
 * 对于数组 L，L[0] = 1
 * 对于数组 R，R[n - 1] = 1
 *
 * 最终 L[i] * R[i] 即为 answer[i] 
 *
 * 实际最终结果可以存在 L 上，即可以返回，所以空间复杂度
 * 主要是数组 R 的占用
 *
 * 可以对以上过程做一个优化，通过一个变量去替代数组 R
 *
 * T(n): O(n)
 * S(n): O(1)
 */
int * productExceptSelf(int *nums, int nums_size, int *return_size)
{
        *return_size = nums_size;
        int *L = malloc(sizeof(int) * nums_size);  

        L[0] = 1;
        for (int i = 1; i < nums_size; i++)
                L[i] = L[i - 1] * nums[i - 1];

        int R = 1;
        for (int i = nums_size - 2; i >= 0; i--) {
                R = R * nums[i + 1];
                L[i] *= R;
        }

        return L;
}
// @lc code=end


