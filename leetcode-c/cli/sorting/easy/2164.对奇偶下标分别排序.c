/*
 * @lc app=leetcode.cn id=2164 lang=c
 *
 * [2164] 对奇偶下标分别排序
 *
 * https://leetcode.cn/problems/sort-even-and-odd-indices-independently/description/
 *
 * algorithms
 * Easy (68.47%)
 * Likes:    13
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 14.6K
 * Testcase Example:  '[4,1,2,3]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。根据下述规则重排 nums 中的值：
 * 
 * 
 * 按 非递增 顺序排列 nums 奇数下标 上的所有值。
 * 
 * 
 * 举个例子，如果排序前 nums = [4,1,2,3] ，对奇数下标的值排序后变
 * 为 [4,3,2,1] 。奇数下标 1 和 3 的值按照非递增顺序重排。
 * 
 * 
 * 按 非递减 顺序排列 nums 偶数下标 上的所有值。
 * 
 * 举个例子，如果排序前 nums = [4,1,2,3] ，对偶数下标的值排序后变
 * 为 [2,1,4,3] 。偶数下标 0 和 2 的值按照非递减顺序重排。
 * 
 * 
 * 
 * 
 * 返回重排 nums 的值之后形成的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,1,2,3]
 * 输出：[2,3,4,1]
 * 解释：
 * 首先，按非递增顺序重排奇数下标（1 和 3）的值。
 * 所以，nums 从 [4,1,2,3] 变为 [4,3,2,1] 。
 * 然后，按非递减顺序重排偶数下标（0 和 2）的值。
 * 所以，nums 从 [4,1,2,3] 变为 [2,3,4,1] 。
 * 因此，重排之后形成的数组是 [2,3,4,1] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,1]
 * 输出：[2,1]
 * 解释：
 * 由于只有一个奇数下标和一个偶数下标，所以不会发生重排。
 * 形成的结果数组是 [2,1] ，和初始数组一样。 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start


static inline int cmp_up(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

static inline int cmp_down(const void *a, const void *b)
{
        return *(int *)b - *(int *)a;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 1. 将奇数坐标和偶数坐标的元素分别取出来放入奇数数组和偶数数组，然后排序
 * 2. 创建答案数组，按照规则将两个数组的元素按照规则放入答案数组
 */
int* sortEvenOdd(int* nums, int nums_size, int* return_size)
{
        int len = (nums_size >> 1) + 1;
        int *even = malloc(sizeof(int) * len);
        int *odd  = malloc(sizeof(int) * len);

        int even_idx = 0, odd_idx = 0;
        for (int i = 0; i < nums_size; i++) {
                if ((i & 1) == 1)
                        odd[odd_idx++] = nums[i];
                else 
                        even[even_idx++] = nums[i];
        }

        qsort(even, even_idx, sizeof(int), cmp_down);
        qsort(odd, odd_idx, sizeof(int), cmp_up);

        *return_size = nums_size;
        int *result = malloc(sizeof(int) * nums_size);
        for (int k = 0; k < nums_size; k++)
                if ((k & 1) == 1)
                        result[k] = odd[--odd_idx];
                else
                        result[k] = even[--even_idx];

        free(even);
        free(odd);

        return result;
}
// @lc code=end


