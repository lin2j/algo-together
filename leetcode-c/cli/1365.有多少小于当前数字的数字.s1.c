/*
 * @lc app=leetcode.cn id=1365 lang=c
 *
 * [1365] 有多少小于当前数字的数字
 *
 * https://leetcode.cn/problems/how-many-numbers-are-smaller-than-the-current-number/description/
 *
 * algorithms
 * Easy (82.41%)
 * Likes:    242
 * Dislikes: 0
 * Total Accepted:    107.2K
 * Total Submissions: 130.1K
 * Testcase Example:  '[8,1,2,2,3]'
 *
 * 给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中
 * 比它小的所有数字的数目。
 * 
 * 换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其
 * 中 j 满足 j != i 且 nums[j] < nums[i] 。
 * 
 * 以数组形式返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [8,1,2,2,3]
 * 输出：[4,0,1,1,3]
 * 解释： 
 * 对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
 * 对于 nums[1]=1 不存在比它小的数字。
 * 对于 nums[2]=2 存在一个比它小的数字：（1）。 
 * 对于 nums[3]=2 存在一个比它小的数字：（1）。 
 * 对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [6,5,4,8]
 * 输出：[2,1,0,3]
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [7,7,7,7]
 * 输出：[0,0,0,0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 500
 * 0 <= nums[i] <= 100
 * 
 * 
 */

#include <stdlib.h>
#include <string.h>

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 考虑到数组元素的范围在 [0, 100]，因此可以使用计数排序
 * 创建计数数组 count，统计每个元素出现的次数，则 cnt[i] 
 * 表示数字 i 出现的次数。那么对于数字 i 而言，小于它的数
 * 目就为 cnt[0...i−1] 的总和。
 *
 * Tc: O(N + K)，K 为值域大小，此处为 101
 * Sc: O(K)，开辟一个值域大小的计数数组
 */
int * smallerNumbersThanCurrent(int *nums, int nums_size, int *return_size)
{
        int count[101] = {0};

        for (int i = 0; i < nums_size; i++)
                count[nums[i]]++;

        for (int i = 1; i < 101; i++)
                count[i] += count[i - 1];

        *return_size = nums_size;
        int *result = malloc(sizeof(int) * nums_size);
        for (int i = 0; i < nums_size; i++)
                result[i] = nums[i] == 0 ? 0 : count[nums[i] - 1];

        return result;
}
// @lc code=end


