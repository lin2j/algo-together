/*
 * @lc app=leetcode.cn id=922 lang=c
 *
 * [922] 按奇偶排序数组 II
 *
 * https://leetcode.cn/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (71.30%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    108.7K
 * Total Submissions: 152.4K
 * Testcase Example:  '[4,2,5,7]'
 *
 * 给定一个非负整数数组 nums，  nums 中一半整数是 奇数 ，一半整数是 偶数 。
 * 
 * 对数组进行排序，以便当 nums[i] 为奇数时，i 也是 奇数 ；当 nums[i] 为偶数时， i 也是 偶数 。
 * 
 * 你可以返回 任何满足上述条件的数组作为答案 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,2,5,7]
 * 输出：[4,5,2,7]
 * 解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,3]
 * 输出：[2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 2 * 10^4
 * nums.length 是偶数
 * nums 中一半是偶数
 * 0 <= nums[i] <= 1000
 * 
 * 
 * 
 * 
 * 进阶：可以不使用额外空间解决问题吗？
 * 
 */
#include <stdlib.h>

// @lc code=start

static void swap(int *a, int *b)
{
        int tmp = *a;
        *a = *b, *b = tmp;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 为数组的偶数下标部分和奇数下标部分分别维护指针 i, j。
 * 随后，在每一步中，如果 nums[i] 为奇数，则不断地向前移动 j（每
 * 次移动两个单位），直到遇见下一个偶数。此时， 可以直接将 nums[i] 
 * 与 nums[j] 交换。
 * 我们不断进行这样的过程，最终能够将所有的整数放在正确的位置上。
 */
int * sortArrayByParityII(int *nums, int nums_size, int *return_size)
{
        for (int i = 0, j = 1; i < nums_size; i += 2) {
                // 此时 i 除为奇数
                if ((nums[i] & 1) == 1) {
                        while((nums[j] & 1) == 1) j += 2;

                        // 此时 j 处为偶数
                        swap(&nums[i], &nums[j]);
                }
        }
        *return_size = nums_size;
        return nums;
}
// @lc code=end


