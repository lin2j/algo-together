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

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 1. 创建数组 sorted 拷贝自 nums 用于将数字从小到大排序
 * 2. 创建哈希表，用于统计对于每个元素x，有多少个小于 x 的数 c
 * 3. 创建答案数组 result，遍历 nums，设索引为 i，当前遍历的元素为 a
 *   3.1 从哈希表中查找 a，则 result[i] 为 a 对应的 c
 *
 * Tc: O(NlogN)
 * Sc: O(N)
 */
int * smallerNumbersThanCurrent(int *nums, int nums_size, int *return_size)
{
        int *sorted = malloc(sizeof(int) * nums_size);
        memcpy(sorted, nums, sizeof(int) * nums_size);
        qsort(sorted, nums_size, sizeof(int), cmp);

        int count_map[101] = {0};
        for (int i = 0; i < nums_size; i++)
                if (count_map[sorted[i]] == 0) {
                        int c = i, j = i - 1;
                        while(j >= 0 && sorted[i] == sorted[j]) {
                                c--;
                                j--;
                        }
                        count_map[sorted[i]] = c;
                }

        *return_size = nums_size;
        int *result = malloc(sizeof(int) * nums_size);
        for (int i = 0; i < nums_size; i++)
                result[i] = count_map[nums[i]];

        return result;
}
// @lc code=end


