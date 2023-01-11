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
 * 使用双指针，设置 left 和 right 指针，left 永远指向第一个 0
 * 的位置，right 需要寻找第一个不为 0 的数，然后 left 和 right
 * 指向的数字进行互换。之后 left 前移一步，right 继续向前找到
 * 不为 0 的数字。如果 right 已经达到末尾，则过程结束
 *
 * T(n): O(n)
 * S(n): O(1)
 */
void moveZeroes(int *nums, int nums_size)
{
        int left = 0;
        int right = 0;

        while(right < nums_size) {
                while(left < nums_size && nums[left] != 0) left++; 
                right = left+1;

                while(right < nums_size && nums[right] == 0) right++;
                if (right < nums_size) {
                        int tmp = nums[left];
                        nums[left] = nums[right];
                        nums[right] = tmp;
                }
        }
}
// @lc code=end


