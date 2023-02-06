/*
 * @lc app=leetcode.cn id=453 lang=c
 *
 * [453] 最小操作次数使数组元素相等
 *
 * https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Medium (61.61%)
 * Likes:    492
 * Dislikes: 0
 * Total Accepted:    70.9K
 * Total Submissions: 115.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。
 * 返回让数组所有元素相等的最小操作次数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：3
 * 解释：
 * 只需要3次操作（注意每次操作会增加两个元素的值）：
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1,1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 答案保证符合 32-bit 整数
 * 
 * 
 */
#include <stdint.h>

// @lc code=start


/*
 * 方便理解：
 * 有 n 根钉子，每次只能敲一根钉子让高度 -1，问敲多少下钉子使得所有钉子高度一样？
 * 答案自然就是把所有的钉子敲到跟最矮的那根一样了
 *
 * 设最后需要操作 k 次，则最终的数组元素之和为 sum + k * (n - 1)
 * 设一开始数组中的最小数为 min，则最终它会变成 min + k，则总和为 n * (min + k)
 * 即有
 *      sum + k * (n - ) = n * (min + k)
 *          sum + nk - k = n * min + nk
 *           nk - k - nk = n * min - sum
 *                     k = sum - n * min
 */
int minMoves(int* nums, int nums_size)
{
        long sum = 0L;
        int min = INT32_MAX;
        for (int i = 0; i < nums_size; i++) {
                sum += nums[i];
                if (nums[i] < min)
                        min = nums[i];
        }

        return sum - nums_size * min;
}
// @lc code=end


