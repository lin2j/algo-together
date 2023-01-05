/*
 * @lc app=leetcode.cn id=2148 lang=c
 *
 * [2148] 元素计数
 *
 * https://leetcode.cn/problems/count-elements-with-strictly-smaller-and-greater-elements/description/
 *
 * algorithms
 * Easy (57.72%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    11.2K
 * Total Submissions: 19.5K
 * Testcase Example:  '[11,7,2,15]'
 *
 * 给你一个整数数组 nums ，统计并返回在 nums 中同时至少具有一个严格较小元素
 * 和一个严格较大元素的元素数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [11,7,2,15]
 * 输出：2
 * 解释：元素 7 ：严格较小元素是元素 2 ，严格较大元素是元素 11 。
 * 元素 11 ：严格较小元素是元素 7 ，严格较大元素是元素 15 。
 * 总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [-3,3,3,90]
 * 输出：2
 * 解释：元素 3 ：严格较小元素是元素 -3 ，严格较大元素是元素 90 。
 * 由于有两个元素的值为 3 ，总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */
#include <stdint.h>
#include <stdlib.h>

// @lc code=start

/*
 * 它「同时具有一个严格较小元素和一个严格较大元素」等价于
 * 它「既不等于数组中的最大值，也不等于数组中元素的最小值」
 *
 * 从数组中找出最小值和最大值，然后除了最大值和最小值之外的
 * 元素即为符合答案的元素
 *
 * T(n): O(n)
 * S(n): O(1)
 *
 */
int countElements(int *nums, int nums_size){
        int min = INT32_MAX, max = INT32_MIN;
        for (int i = 0; i < nums_size; i++) {
                int a = nums[i];
                if (a < min) min = a;
                if (a > max) max = a;
        }

        int ans = 0;
        for (int i = 0; i < nums_size; i++) {
                int a = nums[i];
                if (a != min && a != max)
                        ans++;
        }
        return ans;
}
// @lc code=end


