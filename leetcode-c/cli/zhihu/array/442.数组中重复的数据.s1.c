/*
 * @lc app=leetcode.cn id=442 lang=c
 *
 * [442] 数组中重复的数据
 *
 * https://leetcode.cn/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (75.02%)
 * Likes:    677
 * Dislikes: 0
 * Total Accepted:    103K
 * Total Submissions: 137.3K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 
 * 内，且每个整数出现 一次 或 两次 。请你找出所有出现两次的整数，并以数组
 * 形式返回。
 * 
 * 你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,3,2,7,8,2,3,1]
 * 输出：[2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1,2]
 * 输出：[1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^5
 * 1 <= nums[i] <= n
 * nums 中的每个元素出现 一次 或 两次
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 因为 nums 中的元素是在 [1, n] 范围中，那么对于每一个元素 k，它的正确
 * 位置是在 k - 1。
 *
 * 因此可以将 nums 中的元素放到正确的位置上，而对于重复的数字，只需要将
 * 他放在缺失的数字对应的位置即可。
 *
 * 即我们需要一个操作将 nums 中的元素放到正确的位置上，重复的数字只需要
 * 放在任意不冲突的位置即可。
 *
 * 那么再次遍历 nums，如果 nums[i] - 1 != i，就说明 i 是重复的数字。
 *
 * T(n): O(n)
 * S(n): O(1)
 */
int * findDuplicates(int *nums, int n, int *return_size) 
{
        for (int i = 0; i < n; i++) {
                while(nums[i] != nums[nums[i] - 1]) {
                        // 将 nums[i] 放到正确的位置上
                        // 同时又不影响其他已经在正确位置上的元素
                        int tmp = nums[i];
                        nums[i] = nums[tmp - 1];
                        nums[tmp - 1] = tmp;
                }
        }

        *return_size = 0;
        int *result = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
                if (nums[i] - 1 != i)
                        result[(*return_size)++] = nums[i];
        }

        return result;
}
// @lc code=end


