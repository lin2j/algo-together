/*
 * @lc app=leetcode.cn id=561 lang=c
 *
 * [561] 数组拆分
 *
 * https://leetcode.cn/problems/array-partition/description/
 *
 * algorithms
 * Easy (78.45%)
 * Likes:    323
 * Dislikes: 0
 * Total Accepted:    125.6K
 * Total Submissions: 160.1K
 * Testcase Example:  '[1,4,3,2]'
 *
 * 给定长度为 2n 的整数数组 nums ，你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn)
 * ，使得从 1 到 n 的 min(ai, bi) 总和最大。
 * 
 * 返回该 最大总和 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,4,3,2]
 * 输出：4
 * 解释：所有可能的分法（忽略元素顺序）为：
 * 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
 * 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
 * 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
 * 所以最大总和为 4
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [6,2,6,5,1,2]
 * 输出：9
 * 解释：最优的分法为 (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2
 * + 6 = 9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^4
 * nums.length == 2 * n
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

#include <stdlib.h>

// @lc code=start

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/*
 * 将 nums 按递增排序，a1,b1,a2,b2...an,bn
 * 对于 a1，它是全局最小的，所以任何与之搭档的都会被排除
 * 因此可以选择一个除了 a1 之外最小的数 b1 与之搭档，损失
 * 是最小的，同理 a2 与 b2 搭档损失最小
 *
 */
int arrayPairSum(int *nums, int nums_size)
{
        qsort(nums, nums_size, sizeof(int), cmp);

        int ans = 0;
        for (int i = 0; i < nums_size; i += 2)
                ans += nums[i];

        return ans;
}
// @lc code=end


