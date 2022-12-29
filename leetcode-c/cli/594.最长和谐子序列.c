/*
 * @lc app=leetcode.cn id=594 lang=c
 *
 * [594] 最长和谐子序列
 *
 * https://leetcode.cn/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (56.23%)
 * Likes:    349
 * Dislikes: 0
 * Total Accepted:    76.2K
 * Total Submissions: 135.6K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * 和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。
 * 
 * 现在，给你一个整数数组 nums ，请你在所有可能的子序列中找到最长的和谐子序列的长度。
 * 
 * 数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,2,2,5,2,3,7]
 * 输出：5
 * 解释：最长的和谐子序列是 [3,2,2,2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,1,1,1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^9 
 * 
 * 
 */

#include <stdlib.h>

// @lc code=start

#define MAX(a, b) (a) > (b) ? (a) : (b)

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}


/*
 * 1. 对 nums 从小到大排序
 * 2. 使用滑动窗口统计所有和谐序列的长度，并记录长度最大值
 *
 */
int findLHS(int *nums, int nums_size)
{
        qsort(nums, nums_size, sizeof(int), cmp);

        int ans = 0;

        for (int s = 0, e = 0; e < nums_size; e++) {
                while (nums[e] - nums[s] > 1) 
                        s++;

                if (nums[e] - nums[s] == 1)
                        ans = MAX(ans, e - s + 1);
        }

        return ans;
}
// @lc code=end


