/*
 * @lc app=leetcode.cn id=665 lang=c
 *
 * [665] 非递减数列
 *
 * https://leetcode.cn/problems/non-decreasing-array/description/
 *
 * algorithms
 * Medium (27.63%)
 * Likes:    716
 * Dislikes: 0
 * Total Accepted:    94K
 * Total Submissions: 339.8K
 * Testcase Example:  '[4,2,3]'
 *
 * 给你一个长度为 n 的整数数组 nums ，请你判断在 最多 改变 1 个元素的情况下，
 * 该数组能否变成一个非递减数列。
 * 
 * 我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足
 * nums[i] <= nums[i + 1]。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [4,2,3]
 * 输出: true
 * 解释: 你可以通过把第一个 4 变成 1 来使得它成为一个非递减数列。
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [4,2,1]
 * 输出: false
 * 解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^4
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */
#include <stdbool.h>

// @lc code=start

/*
 * 当遇到 nums[i] > nums[i+1] 时，有两种修改方案
 * 1. 将 nums[i] 变小
 * 2. 将 nums[i+1] 变大
 *
 * 但是会有问题，如果 i-1 是合法的，那么
 * 1. 要考虑 nums[i] 变小之后，nums[i-1] 和 nums[i] 的关系  
 * 2. 要考虑 nums[i+1] 变大之后，i 之后的元素的非递减性
 *
 * 因此需要减小 1、2 改变带来的影响，所以
 * 1. nums[i] 变小时，尽量使得 nums[i] 和 nums[i+1] 相等
 * 2. nums[i+1] 变大时，尽量使得 nums[i+1] 和 nums[i] 相等
 *
 * 算法过程：
 * 1. 创建变量 n = nums_size - 1, changable 标记 nums[0] 和 nums[1] 的关系
 *   1.1 如果 nums[0] 比 nums[1] 大，则后面不可再修改 changeable 为 false
 *
 * 2. 遍历 nums 数组，索引从 1 开始到 n （不包含n）结束
 *   2.1 如果 nums[i] <= nums[i+1]，则满足非递减要求，继续遍历
 *   2.2 如果 nums[i] > nums[i+1] 则先判断是否还能修改，若不能直接返回false
 *   2.3 如果可以修改则按照上述影响最小的方式进行修改，将 changable 设为 false 
 *
 * 3. 遍历结束则代表当前数组已经是非递减，返回 true
 */
bool checkPossibility(int* nums, int nums_size)
{
        if (nums_size == 1) 
                return true;

        int n = nums_size - 1;
        // 如果一开始就是颠倒的，那么后面将不可以在修改
        bool changable = nums[0] <= nums[1];
        for (int i = 1; i < n; i++) {
                if (nums[i] <= nums[i+1])
                        continue;

                if (!changable)
                        return false;

                // 一旦执行到这里，必定会用掉一次修改机会
                // 此时必有 nums[i] >= nums[i-1]
                if (nums[i+1] >= nums[i-1])
                        nums[i] = nums[i+1];
                else
                        nums[i+1] = nums[i];
                changable = false;
        }
                        
        return true;
}
// @lc code=end

