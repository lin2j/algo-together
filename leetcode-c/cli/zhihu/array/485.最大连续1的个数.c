/*
 * @lc app=leetcode.cn id=485 lang=c
 *
 * [485] 最大连续 1 的个数
 *
 * https://leetcode.cn/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (61.05%)
 * Likes:    360
 * Dislikes: 0
 * Total Accepted:    185.9K
 * Total Submissions: 304.4K
 * Testcase Example:  '[1,1,0,1,1,1]'
 *
 * 给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,0,1,1,1]
 * 输出：3
 * 解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：nums = [1,0,1,1,0,1]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] 不是 0 就是 1.
 * 
 * 
 */

#include <stdint.h>

// @lc code=start

#define MAX(a, b) (a) > (b) ? (a) : (b)

/*
 * 1. 遍历 nusm 数组，设变量 left = 0，right = 0
 * 2. right 一直往前遍历，当 nums[right] == 0 时，统计 right - left
 *    并和答案 ans 进行比较，取较大者
 * 3. 如果 right 没有指向最后一个元素，则继续遍历，从下一个 1 开始
 * 4. right 指向最后一个元素，整个过程结束
 */
int findMaxConsecutiveOnes(int *nums, int nums_size)
{
        int ans = INT32_MIN;
        int left = 0, right = 0;
        while(right < nums_size) {
                while(right < nums_size && nums[right] == 1)
                        right++;
                ans = MAX(ans, right - left);
                while(right < nums_size && nums[right] == 0)
                        right++;
                left = right;
        }
        return ans;
}
// @lc code=end


