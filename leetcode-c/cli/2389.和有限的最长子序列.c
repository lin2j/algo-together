/*
 * @lc app=leetcode.cn id=2389 lang=c
 *
 * [2389] 和有限的最长子序列
 *
 * https://leetcode.cn/problems/longest-subsequence-with-limited-sum/description/
 *
 * algorithms
 * Easy (66.47%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 15.1K
 * Testcase Example:  '[4,5,2,1]\n[3,10,21]'
 *
 * 给你一个长度为 n 的整数数组 nums ，和一个长度为 m 的整数数组 queries 。
 * 
 * 返回一个长度为 m 的数组 answer ，其中 answer[i] 是 nums 中 元素之和小于
 * 等于 queries[i] 的 子序列 的 最大长度  。
 * 
 * 子序列 是由一个数组删除某些元素（也可以不删除）但不改变剩余元素顺序得到
 * 的一个数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,5,2,1], queries = [3,10,21]
 * 输出：[2,3,4]
 * 解释：queries 对应的 answer 如下：
 * - 子序列 [2,1] 的和小于或等于 3 。可以证明满足题目要求的子序列的最大长度是 2 ，所以 answer[0] = 2 。
 * - 子序列 [4,5,1] 的和小于或等于 10 。可以证明满足题目要求的子序列的最大长度是 3 ，所以 answer[1] = 3 。
 * - 子序列 [4,5,2,1] 的和小于或等于 21 。可以证明满足题目要求的子序列的最大长度是 4 ，所以 answer[2] = 4 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,3,4,5], queries = [1]
 * 输出：[0]
 * 解释：空子序列是唯一一个满足元素和小于或等于 1 的子序列，所以 answer[0] = 0 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * m == queries.length
 * 1 <= n, m <= 1000
 * 1 <= nums[i], queries[i] <= 10^6
 * 
 * 
 */
#include <stdint.h>
#include <stdlib.h>

// @lc code=start

static inline int intcmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/*
 * 元素之和小于等于 k 的最大序列长度
 */
int max_sequence(int *nums, int nums_size, int k)
{
        int size = 0;
        for(int i = 0, j = 0, sum = 0; j < nums_size; j++) {
                if (sum + nums[j] > k)
                        break;
                sum += nums[j];
                size++;
        }
        return size;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* answerQueries(int *nums, int nums_size,
                   int *queries, int queries_size,
                   int* return_size)
{
        qsort(nums, nums_size, sizeof(int), intcmp);

        int *result = malloc(sizeof(int) * queries_size);
        *return_size = queries_size;
        for (int i = 0; i < queries_size; i++)
                result[i] = max_sequence(nums, nums_size, queries[i]);

        return result;
}
// @lc code=end


