/*
 * @lc app=leetcode.cn id=1984 lang=c
 *
 * [1984] 学生分数的最小差值
 *
 * https://leetcode.cn/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/
 *
 * algorithms
 * Easy (62.26%)
 * Likes:    97
 * Dislikes: 0
 * Total Accepted:    43.9K
 * Total Submissions: 70.5K
 * Testcase Example:  '[90]\n1'
 *
 * 给你一个 下标从 0 开始 的整数数组 nums ，其中 nums[i] 表示第 i 名学生的分
 * 数。另给你一个整数 k 。
 * 
 * 从数组中选出任意 k 名学生的分数，使这 k 个分数间 最高分 和 最低分 的 差值
 * 达到 最小化 。
 * 
 * 返回可能的 最小差值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [90], k = 1
 * 输出：0
 * 解释：选出 1 名学生的分数，仅有 1 种方法：
 * - [90] 最高分和最低分之间的差值是 90 - 90 = 0
 * 可能的最小差值是 0
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [9,4,1,7], k = 2
 * 输出：2
 * 解释：选出 2 名学生的分数，有 6 种方法：
 * - [9,4,1,7] 最高分和最低分之间的差值是 9 - 4 = 5
 * - [9,4,1,7] 最高分和最低分之间的差值是 9 - 1 = 8
 * - [9,4,1,7] 最高分和最低分之间的差值是 9 - 7 = 2
 * - [9,4,1,7] 最高分和最低分之间的差值是 4 - 1 = 3
 * - [9,4,1,7] 最高分和最低分之间的差值是 7 - 4 = 3
 * - [9,4,1,7] 最高分和最低分之间的差值是 7 - 1 = 6
 * 可能的最小差值是 2
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= nums.length <= 1000
 * 0 <= nums[i] <= 10^5
 * 
 * 
 */
#include <stdint.h>
#include <stdlib.h>

// @lc code=start
#define MIN(a, b) (a) > (b) ? (b) : (a)

static inline int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/**
 * 将数组排序，然后使用大小为 k 的滑动窗口，不断统计每个窗口
 * 的最小差值。
 *
 * 在窗口中，nums[i + k - 1] 为最大值，nums[i] 为最小值
 */
int minimumDifference(int *nums, int nums_size, int k)
{
        qsort(nums, nums_size, sizeof(int), cmp);

        int result = INT32_MAX;
        for (int i = 0; i + k - 1 < nums_size; i++) {
                int d = nums[i + k - 1] - nums[i];
                result = MIN(result, d);
        }
        return result;
}
// @lc code=end


