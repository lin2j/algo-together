/*
 * @lc app=leetcode.cn id=448 lang=c
 *
 * [448] 找到所有数组中消失的数字
 *
 * https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (65.86%)
 * Likes:    1137
 * Dislikes: 0
 * Total Accepted:    251.7K
 * Total Submissions: 382.2K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所
 * 有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,3,2,7,8,2,3,1]
 * 输出：[5,6]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1]
 * 输出：[2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 
 * 1 
 * 
 * 
 * 进阶：你能在不使用额外空间且时间复杂度为 O(n) 的情况下解决这个问题吗? 
 * 你可以假定返回的数组不算在额外空间内。
 * 
 */
#include <stdlib.h>

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 
 * 输入数组的长度为 n，而元素 x 是在 [1,n] 之间，即若没有出现缺失的数字，
 * 那么对所有 nums[x - 1] += n 的话，最终整个数组所有元素都将大于 n。
 *
 * 回到题目上。
 *
 * 因为 [1, n] 中的部分数字没有出现在 nums[i] 中，即部分数字会重复。
 * 若采用上述的方式，对于所有的 nusm[i] 都执行 nums[nums[i] - 1] += n，
 * 那么对于缺失的数字 m 来说，索引 m - 1 位置的元素不会大于 n 。
 *
 * 需要注意的是，nums[i] 位置的元素可能已经经过 +n 的操作，所以 nums[i] - 1 
 * 需要对 n 取模以保证数组不会越界。
 *
 *
 */
int* findDisappearedNumbers(int* nums, int nums_size, int* return_size)
{
        int n = nums_size;
        for (int i = 0; i < n; i++) {
                int x = (nums[i] - 1) % n;
                nums[x] += n;
        }

        *return_size = 0;
        int *result = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
                if (nums[i] <= n)
                        result[(*return_size)++] = i + 1;
                else
                        nums[i] %= n; // 还原 nums 数组

        return result;
}
// @lc code=end


