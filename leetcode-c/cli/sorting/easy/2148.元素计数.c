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
#include <stdlib.h>

// @lc code=start


static inline int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/*
 * 先将数组排序，然后从两边去掉最大值和最小值，那么剩下的就是
 * 符合条件的元素
 * T(n): O(nlogn)
 * S(n): O(logn)
 *
 */
int countElements(int *nums, int nums_size){
        if (nums_size < 3)
                return 0;

        qsort(nums, nums_size, sizeof(int), cmp);

        int left = 0, right = nums_size - 1;
        int min = nums[0], max = nums[nums_size - 1];
        while(left <= right) {
                if (nums[left] == min) left++;
                if (nums[right] == max) right--;
                if (nums[left] != min && nums[right] != max)
                        break;
        }
        if (right < left) return 0;

        return right - left + 1; 
}
// @lc code=end


