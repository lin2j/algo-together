/*
 * @lc app=leetcode.cn id=414 lang=c
 *
 * [414] 第三大的数
 *
 * https://leetcode.cn/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (39.69%)
 * Likes:    395
 * Dislikes: 0
 * Total Accepted:    129.5K
 * Total Submissions: 326.1K
 * Testcase Example:  '[3,2,1]'
 *
 * 给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[3, 2, 1]
 * 输出：1
 * 解释：第三大的数是 1 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：[1, 2]
 * 输出：2
 * 解释：第三大的数不存在, 所以返回最大的数 2 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：[2, 2, 3, 1]
 * 输出：1
 * 解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
 * 此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * 
 * 
 * 
 * 
 * 进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？
 * 
 */

#include <stdlib.h>

// @lc code=start


int cmp(const void *a, const void *b)
{
        // 直接 b - a 容易因为 1 - (-2147483648) 这种情况
        // 而导致 int 溢出
        return *(int *)b > *(int *)a;
}

/**
 * 1. 将 nums 按照递增排序
 * 2. 从后往前遍历，设置变量 pre 记录上一个数字，设置 k = 3
 *   2.1 如果 pre 跟当前数字相等，则跳过当前数字
 *   2.2 如果 pre 跟当前数字不相等，则令 pre = 当前数字，k 减一
 *     2.2.1 如果 k 为 0，则返回当前数字
 * 3. 如果遍历完 nums 都没有发现第三大的数字，则返回 nums[nums_size - 1]
 */
int thirdMax(int *nums, int nums_size)
{
        qsort(nums, nums_size, sizeof(int), cmp);

        int pre = 0, k = 3;
        for (int i = 0; i < nums_size; i++) {
                if (i == 0) {
                        pre = nums[i];
                        k--;
                        continue;
                } 
                if (nums[i] == pre) continue;
                pre = nums[i];
                if (--k == 0) return nums[i];
        }

        return nums[0];
}
// @lc code=end


