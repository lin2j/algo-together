/*
 * @lc app=leetcode.cn id=41 lang=c
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode.cn/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (42.85%)
 * Likes:    1706
 * Dislikes: 0
 * Total Accepted:    271.3K
 * Total Submissions: 632.9K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,0]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 * 
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
 */
#include <stdlib.h>

// @lc code=start

/*
 * 对于长度为 N 的数组，第一个正数的可能范围为 [1, N+1]，
 * 因为如果 1 到 N 都出现了，那么 N+1 就是第一个正数，
 * 所以我们只需要考虑 [1,N] 内的数字即可。
 *
 * 如果有一个方法在 O(1) 的时间内判断 [1,N] 内的数是否在 
 * nums 中，则可以实现 O(N) 时间复杂度的要求。
 *
 * 可以采用原地哈希的方法，取 nums 内的数字 k，如果 k 的绝
 * 对值 |k|（因为 k 可能已经是负数）属于 [1, N]，则 |k|-1 
 * 对应着 nums 的一个索引位置，可以对该位置的元素进行“标记”，
 * 如果该位置已经"标记"过，则不用操作，表示|k| 这个数字出现过。
 *
 * “标记” 的方法是对 [1,N] 内的数字 k 对应的 k-1 位置取相反数，
 * 即若 nums[k-1] 为正数 n，取反之后为 -n。最终只有遍历数组，找
 * 到第一个元素值小于 0 的索引 i，则 i + 1 就是第一个正数。
 *
 * 因为“标记”的时候，可能碰到 [1, N] 区间之外的数字，可
 * 以将这些数字统一设置为 N+1。
 */
int firstMissingPositive(int *nums, int n)
{
        for (int i = 0; i < n; i++) {
                int k = nums[i];
                if (k < 1 || k > n)
                        nums[i] = n + 1;
        }

        for (int i = 0; i < n; i++) {
                int k = abs(nums[i]);
                // nums[k - 1] < 0 表示已经标记过
                if (k >= 1 && k <= n && nums[k - 1] > 0)
                        nums[k - 1] *= -1;
        }

        for (int i = 0; i < n; i++)
                if (nums[i] > 0)
                        return i + 1;

        return n + 1;
}
// @lc code=end


