/*
 * @lc app=leetcode.cn id=1608 lang=c
 *
 * [1608] 特殊数组的特征值
 *
 * https://leetcode.cn/problems/special-array-with-x-elements-greater-than-or-equal-x/description/
 *
 * algorithms
 * Easy (61.62%)
 * Likes:    183
 * Dislikes: 0
 * Total Accepted:    51.2K
 * Total Submissions: 83.1K
 * Testcase Example:  '[3,5]'
 *
 * 给你一个非负整数数组 nums 。如果存在一个数 x ，使得 nums 中恰好有 x 个元素
 * 大于或者等于 x ，那么就称 nums 是一个 特殊数组，而 x 是该数组的 特征值 。
 * 
 * 注意： x 不必 是 nums 的中的元素。
 * 
 * 如果数组 nums 是一个 特殊数组 ，请返回它的特征值 x 。否则，返回 -1 。可以证
 * 明的是，如果 nums 是特殊数组，那么其特征值 x 是唯一的 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [3,5]
 * 输出：2
 * 解释：有 2 个元素（3 和 5）大于或等于 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [0,0]
 * 输出：-1
 * 解释：没有满足题目要求的特殊数组，故而也不存在特征值 x 。
 * 如果 x = 0，应该有 0 个元素 >= x，但实际有 2 个。
 * 如果 x = 1，应该有 1 个元素 >= x，但实际有 0 个。
 * 如果 x = 2，应该有 2 个元素 >= x，但实际有 0 个。
 * x 不能取更大的值，因为 nums 中只有两个元素。
 * 
 * 示例 3：
 * 
 * 输入：nums = [0,4,3,0,4]
 * 输出：3
 * 解释：有 3 个元素大于或等于 3 。
 * 
 * 
 * 示例 4：
 * 
 * 输入：nums = [3,6,7,7,0]
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start

int cmp(const void *a, const void *b)
{
        return *(int *)b - *(int *)a;
}


/**
 * 如果一个数组是特殊数组，那么他的特征值范围
 * 在 (0, nums_size] 中，因此可以将数组排序后，
 * 遍历 (0, nums_size] 中的数 h，根据题目的规
 * 则在 nums 中统计大于等于 h 的元素个数 c，最
 * 终如果 c == h，则 h 为特征值
 *
 * 1. 将数组降序排序
 * 2. 若 h 为特征值，则 nums 中恰好有 i 个元素
 *    大于等于 h，即 nums[h - 1] >= h，且 nums[h]
 *    （如果存在）必须小于 h
 *
 */
int specialArray(int *nums, int nums_size)
{
        qsort(nums, nums_size, sizeof(int), cmp);

        for (int h = nums_size; h > 0; h--) {
                if (nums[h - 1] >= h 
                        && (h == nums_size || nums[h] < h))
                        return h;
        }
        return -1;
}
// @lc code=end


