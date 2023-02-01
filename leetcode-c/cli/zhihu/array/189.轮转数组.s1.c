/*
 * @lc app=leetcode.cn id=189 lang=c
 *
 * [189] 轮转数组
 *
 * https://leetcode.cn/problems/rotate-array/description/
 *
 * algorithms
 * Medium (44.27%)
 * Likes:    1697
 * Dislikes: 0
 * Total Accepted:    601.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,3,4,5,6,7], k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右轮转 1 步: [7,1,2,3,4,5,6]
 * 向右轮转 2 步: [6,7,1,2,3,4,5]
 * 向右轮转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：nums = [-1,-100,3,99], k = 2
 * 输出：[3,99,-1,-100]
 * 解释: 
 * 向右轮转 1 步: [99,-1,-100,3]
 * 向右轮转 2 步: [3,99,-1,-100]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^5
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
 * 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 * 
 */
#include <stdlib.h>

// @lc code=start

/*
 * 创建答案数组 result，对于当前元素 nums[i]，它轮转 k 次之后的位置
 * 为 (i + k) mod n，n 为数组长度
 *
 * T(n): O(n)
 * S(n): O(n)
 */
void rotate(int *nums, int nums_size, int k)
{
        if (k == 0) return;

        int *result = malloc(sizeof(int) * nums_size);

        for (int i = 0; i < nums_size; i++) {
                int j = (i + k) % nums_size;
                result[j] = nums[i];
        }

        for (int i = 0; i < nums_size; i++)
                nums[i] = result[i];

        free(result);

}
// @lc code=end


