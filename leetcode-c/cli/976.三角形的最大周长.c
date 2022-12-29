/*
 * @lc app=leetcode.cn id=976 lang=c
 *
 * [976] 三角形的最大周长
 *
 * https://leetcode.cn/problems/largest-perimeter-triangle/description/
 *
 * algorithms
 * Easy (57.73%)
 * Likes:    223
 * Dislikes: 0
 * Total Accepted:    78.2K
 * Total Submissions: 135.4K
 * Testcase Example:  '[2,1,2]'
 *
 * 给定由一些正数（代表长度）组成的数组 nums ，返回 由其中三个长度组成的、面积
 * 不为零的三角形的最大周长 。如果不能形成任何面积不为零的三角形，返回0。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,1,2]
 * 输出：5
 * 解释：你可以用三个边长组成一个三角形:1 2 2。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,1,10]
 * 输出：0
 * 解释：
 * 你不能用边长 1,1,2 来组成三角形。
 * 不能用边长 1,1,10 来构成三角形。
 * 不能用边长 1、2 和 10 来构成三角形。
 * 因为我们不能用任何三条边长来构成一个非零面积的三角形，所以我们返回 0。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^6
 * 
 * 
 */

#include <stdlib.h>

// @lc code=start

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/*
 * 1. 将 nums 从小到大排序 
 * 2. 从后往前遍历，令 i = nums_size - 1，
 *    每一个数字都作为最大边去尝试构成周长最大的三角形
 *   2.1 如果 n[i] < n[i-1] + n[i-2]，则三者可以构成三角形，且周长最大
 * 3. 如果遍历完数组都没有发现满足条件的边，则返回 0
 *
 */
int largestPerimeter(int *nums, int nums_size){
        qsort(nums, nums_size, sizeof(int), cmp);

        for (int i = nums_size - 1; i >= 2; i--) {
                if (nums[i] < nums[i - 1] + nums[i - 2])
                        return nums[i] + nums[i - 1] + nums[i - 2];
        }
        return 0;
}
// @lc code=end


