/*
 * @lc app=leetcode.cn id=15 lang=c
 *
 * [15] 三数之和
 *
 * https://leetcode.cn/problems/3sum/description/
 *
 * algorithms
 * Medium (38.06%)
 * Total Accepted:    1.9M
 * Total Submissions: 4.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 
 * 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 
 *
 * 请你返回所有和为 0 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1,1]
 * 输出：[]
 * 解释：唯一可能的三元组和不为 0 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * 解释：唯一可能的三元组和为 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

#include <stdlib.h>


// @lc code=start

/**
 * 确保空间足够
 */
static void ensure_cap(int ***matrix, int size, int *cap_ptr, int **col_sizes)
{
        int cap = *cap_ptr;

        if (*matrix == NULL) {
                *matrix = malloc(sizeof(int *) * cap);
                *col_sizes = malloc(sizeof(int) * cap);
        }

        if (size == cap) {
                cap = cap << 1;
                size_t new_cap = sizeof(int *) * cap;
                size_t new_col_size = sizeof(int) * cap;
                *matrix = realloc(*matrix, new_cap);
                *col_sizes = realloc(*col_sizes, new_col_size);
                *cap_ptr = cap;
        }
}

static int int_cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/**
 * 1. 将数组按从小到大的规则排序。
 * 2. 设置三个索引i,j,k，其中，k从0开始往后移动，直到k所在的元素大于0，算法结束
 * 3. 在k移动到每个位置时，i 指向 k+1 并往右移动，j 从最后一个元素开始往左移动
 *    在 i 和 j 移动的过程中，需要进行判断，找出可能的三元组
 *    3.1 当三者和超过 0 时，j--；当三者和小于 0 时，i++
 *    3.2 当三者和为 0 时，保存 ijk 的元素，并且 i++，j--，并且跳过所有重复的
 *        n[i] 和 n[j]，防止记录到重复的元组
 *    3.3 当 i >= j 时，结束当前循环
 *
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int ** threeSum(int *nums, int n_size, int *ret_size, int **ret_col_sizes) 
{
        qsort(nums, n_size, sizeof(int), int_cmp);

        *ret_size = 0;
        int base = 1 << 4;
        int **ans = NULL;
        int i = 0, j = 0, k = 0;
        int sum = 0;
        for (; k < n_size - 2 && nums[k] <= 0; k++) {
                if (k > 0 && nums[k - 1] == nums[k]) continue;
                i = k + 1;
                j = n_size - 1;
                while (i < j) {
                        sum = nums[i] + nums[j] + nums[k];
                        if (sum < 0) {
                                while(++i < j && nums[i - 1] == nums[i]);
                                continue;
                        }
                        if (sum > 0) {
                                while(i < --j && nums[j + 1] == nums[j]);
                                continue;
                        }
                        // sum == 0
                        ensure_cap(&ans, *ret_size, &base,  ret_col_sizes);
                        ans[*ret_size] = malloc(sizeof(int) * 3);
                        ans[*ret_size][0] = nums[k];
                        ans[*ret_size][1] = nums[i];
                        ans[*ret_size][2] = nums[j];
                        (*ret_col_sizes)[*ret_size] = 3;
                        (*ret_size)++;

                        while(++i < j && nums[i - 1] == nums[i]);
                        while(i < --j && nums[j + 1] == nums[j]);
                }
        }
        return ans;
}

// @lc code=end

