/*
 * @lc app=leetcode.cn id=2089 lang=c
 *
 * [2089] 找出数组排序后的目标下标
 *
 * https://leetcode.cn/problems/find-target-indices-after-sorting-array/description/
 *
 * algorithms
 * Easy (79.46%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    15.7K
 * Total Submissions: 19.8K
 * Testcase Example:  '[1,2,5,2,3]\n2'
 *
 * 给你一个下标从 0 开始的整数数组 nums 以及一个目标元素 target 。
 * 
 * 目标下标 是一个满足 nums[i] == target 的下标 i 。
 * 
 * 将 nums 按 非递减 顺序排序后，返回由 nums 中目标下标组成的列表。
 * 如果不存在目标下标，返回一个 空 列表。返回的列表必须按 递增
 * 顺序排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,5,2,3], target = 2
 * 输出：[1,2]
 * 解释：排序后，nums 变为 [1,2,2,3,5] 。
 * 满足 nums[i] == 2 的下标是 1 和 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,2,5,2,3], target = 3
 * 输出：[3]
 * 解释：排序后，nums 变为 [1,2,2,3,5] 。
 * 满足 nums[i] == 3 的下标是 3 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,2,5,2,3], target = 5
 * 输出：[4]
 * 解释：排序后，nums 变为 [1,2,2,3,5] 。
 * 满足 nums[i] == 5 的下标是 4 。
 * 
 * 
 * 示例 4：
 * 
 * 输入：nums = [1,2,5,2,3], target = 4
 * 输出：[]
 * 解释：nums 中不含值为 4 的元素。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 1 <= nums[i], target <= 100
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start

static inline int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 将 nums 非递减排序，遍历 nums 将符合条件的下标选出来
 */
int* targetIndices(int *nums, int nums_size, 
                   int target, int *return_size)
{
        qsort(nums, nums_size, sizeof(int), cmp);

        int *result = malloc(sizeof(int) * nums_size);
        int idx = 0;
        for (int i = 0; i < nums_size; i++)
                if (nums[i] == target)
                        result[idx++] = i;

        *return_size = idx;
        return result;
}
// @lc code=end


