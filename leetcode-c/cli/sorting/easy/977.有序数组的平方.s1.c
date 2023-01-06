/*
 * @lc app=leetcode.cn id=977 lang=c
 *
 * [977] 有序数组的平方
 *
 * https://leetcode.cn/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (68.66%)
 * Likes:    686
 * Dislikes: 0
 * Total Accepted:    449.9K
 * Total Submissions: 655.2K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 10^4
 * -10^4 
 * nums 已按 非递减顺序 排序
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 请你设计时间复杂度为 O(n) 的算法解决本问题
 * 
 * 
 */

#include <stdlib.h>

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 1 如果数组全为非负数，那么平方之后依旧保持递增
 * 2 如果数组全为负数，那么平方之后为倒序，需要反转数组
 * 3 如果数组中有非负数和负数，那么平方之后数组将成为先递减再递增的样子
 *   3.1 使用两个变量 i = 0, j = nums_size - 1，分别指向两个序列的最大值
 *   3.2 将二者的最大值进行对比，较大值放入答案的尾部
 *
 * 根据第三种情况，可以
 * 1. 将第一种情况归结为负数的平方序列长度为0
 * 2. 将第二种情况归结为非负数的平方序列长度为0
 */
int* sortedSquares(int *nums, int len_n, int* return_size)
{
        *return_size = len_n;
        int *ans = malloc(sizeof(int) * len_n);

        for (int i = 0; i < len_n; i++)
                nums[i] = nums[i] * nums[i];

        for (int i = 0, j = len_n - 1, pos = len_n - 1; i <= j; ) {
                if (nums[i] > nums[j]) {
                        ans[pos--] = nums[i];
                        i++;
                } else {
                        ans[pos--] = nums[j];
                        j--;
                }
        }
        return ans;
}
// @lc code=end


