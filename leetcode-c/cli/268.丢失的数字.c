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

int cmp(const void *_a, const void *_b)
{
        return *(int *)_a - *(int *)_b;
}

/**
 * 排序，之后将数组元素与索引相比较，当索引与数组
 * 不同时，表示该索引为缺失的数字
 * 如果遍历完数组，仍然没有出现缺失数字，则表示 
 * 缺失的数字是 n
 */
int missingNumber(int *nums, int nums_size)
{
        qsort(nums, nums_size, sizeof(int), cmp);

        for (int i = 0; i < nums_size; i++)
                if (nums[i] != i)
                        return i;
        return nums_size;
}
// @lc code=end


