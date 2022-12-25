/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 多数元素
 *
 * https://leetcode.cn/problems/majority-element/description/
 *
 * algorithms
 * Easy (66.90%)
 * Likes:    1641
 * Dislikes: 0
 * Total Accepted:    628.2K
 * Total Submissions: 938.9K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,2,3]
 * 输出：3
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,1,1,1,2,2]
 * 输出：2
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 * 
 * 
 * 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
 * 
 */

// @lc code=start


/*
 * 设置一个候选项并记录候选项的出现次数，遍历数组：
 * 1. 当目标与候选项相等时，候选项次数增加，继续遍历
 * 2. 当目标与候选项不相等时，
 *      2.1 当候选项的次数已经是 0 时，则候选项更换为当前遍历的元素
 *      2.2 当候选项次数不为 0 时，则减一
 */
int majorityElement(int *nums, int nums_size){
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i < nums_size; i++) {
                if (nums[i] == candidate) {
                        count++;
                } else if (count == 0) {
                        candidate = nums[i];
                        count = 1;
                } else {
                        count--;
                }
        }
        return candidate;
}
// @lc code=end

