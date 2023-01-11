/*
 * @lc app=leetcode.cn id=283 lang=c
 *
 * [283] 移动零
 *
 * https://leetcode.cn/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (63.96%)
 * Likes:    1845
 * Dislikes: 0
 * Total Accepted:    947.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，
 * 同时保持非零元素的相对顺序。
 * 
 * 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [0]
 * 输出: [0]
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：你能尽量减少完成的操作次数吗？
 * 
 */

// @lc code=start

/*
 * 两次遍历
 *
 * 第一次遍历，设置变量 j=0 来记录当前有多少个非零元素，
 * 在第一次遍历的时候，每遇到一个非零元素将设置到 j 处
 * 然后 j++，最终所有的非零元素到移动到头部，而 j 记录
 * 了有多少个非零元素。
 *
 * 第二次遍历则是将 j 以及之后的位置都填充 0
 *
 * T(n): O(n)
 * S(n): O(1)
 */
void moveZeroes(int *nums, int nums_size)
{
        int j = 0;

        for (int i = 0; i < nums_size; i++)
                if (nums[i] != 0)
                        nums[j++] = nums[i];

        for (int i = j; j < nums_size; j++)
                nums[j] = 0;
}
// @lc code=end


