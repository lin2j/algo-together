/*
 * @lc app=leetcode.cn id=1913 lang=c
 *
 * [1913] 两个数对之间的最大乘积差
 *
 * https://leetcode.cn/problems/maximum-product-difference-between-two-pairs/description/
 *
 * algorithms
 * Easy (81.53%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    17.3K
 * Total Submissions: 21.2K
 * Testcase Example:  '[5,6,2,7,4]'
 *
 * 两个数对 (a, b) 和 (c, d) 之间的 乘积差 定义为 (a * b) - (c * d) 。
 * 
 * 
 * 例如，(5, 6) 和 (2, 7) 之间的乘积差是 (5 * 6) - (2 * 7) = 16 。
 * 
 * 
 * 给你一个整数数组 nums ，选出四个 不同的 下标 w、x、y 和 z ，
 * 使数对 (nums[w], nums[x]) 和 (nums[y], nums[z]) 之间的 乘积差 取到 最大值 。
 * 
 * 返回以这种方式取得的乘积差中的 最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [5,6,2,7,4]
 * 输出：34
 * 解释：可以选出下标为 1 和 3 的元素构成第一个数对 (6, 7) 以及下标 2 和 4 构成第二个数对 (2, 4)
 * 乘积差是 (6 * 7) - (2 * 4) = 34
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [4,2,5,9,7,4,8]
 * 输出：64
 * 解释：可以选出下标为 3 和 6 的元素构成第一个数对 (9, 8) 以及下标 1 和 5 构成第二个数对 (2, 4)
 * 乘积差是 (9 * 8) - (2 * 4) = 64
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 4 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */
#include <stdint.h>

// @lc code=start
int maxProductDifference(int *nums, int nums_size)
{
        int min1 = INT32_MAX, min2 = INT32_MAX;
        int max1 = INT32_MIN, max2 = INT32_MIN;

        int n;
        for (int i = 0; i < nums_size; i++) {
                n = nums[i];
                if (n > max1) {
                        max2 = max1;
                        max1 = n;
                } else if (n > max2) {
                        max2 = n;
                }

                if (n < min1) {
                        min2 = min1;
                        min1 = n;
                } else if (n < min2) {
                        min2 = n;
                }
        }
        return (max1 * max2) - (min1 * min2);
}
// @lc code=end


