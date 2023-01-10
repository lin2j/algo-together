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
 * 1. 遍历数组 nums，对于遍历的元素 x，将索引位置为 x-1 的元素进行 +n 操作
 * 2. 遍历 [1, n]，设当前元素为 i，如果 nums[i] 大于 2 * n，则数字 
 *    i + 1 出现两次
 *
 * T(n): O(n)
 * S(n): O(1)
 */
int * findDuplicates(int *nums, int n, int *return_size) 
{
        for (int i = 0; i < n; i++) {
                int x = (nums[i] - 1) % n;
                nums[x] += n;
        }

        *return_size = 0;
        int *result = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
                if (nums[i] > 2 * n)
                        result[(*return_size)++] = i + 1;
        }

        return result;
}
// @lc code=end


