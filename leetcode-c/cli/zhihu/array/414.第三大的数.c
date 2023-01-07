/*
 * @lc app=leetcode.cn id=414 lang=c
 *
 * [414] 第三大的数
 *
 * https://leetcode.cn/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (39.69%)
 * Likes:    395
 * Dislikes: 0
 * Total Accepted:    129.5K
 * Total Submissions: 326.1K
 * Testcase Example:  '[3,2,1]'
 *
 * 给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[3, 2, 1]
 * 输出：1
 * 解释：第三大的数是 1 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：[1, 2]
 * 输出：2
 * 解释：第三大的数不存在, 所以返回最大的数 2 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：[2, 2, 3, 1]
 * 输出：1
 * 解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
 * 此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
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
 * 
 * 
 * 进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？
 * 
 */
#include <stdint.h>

// @lc code=start


/*
 * 设置三个变量 max1, max2, max3 分别记录数组中的
 * 第一大、第二大、第三大 数字，返回 max3
 *
 */
int thirdMax(int *nums, int nums_size){
        int max1 = INT32_MIN;
        int max2 = INT32_MIN;
        int max3 = INT32_MIN;

        for (int i = 0; i < nums_size; i++) {
                int n = nums[i];
                if (n > max1) {
                        max3 = max2;
                        max2 = max1;
                        max1 = n;
                } else if (n > max2 && n != max1) {
                        max3 = max2;
                        max2 = n;
                } else if (n > max3 && n != max2) {
                        max3 = n;
                }
        }

        return max3;
}
// @lc code=end


