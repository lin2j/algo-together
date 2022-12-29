/*
 * @lc app=leetcode.cn id=905 lang=c
 *
 * [905] 按奇偶排序数组
 *
 * https://leetcode.cn/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (71.18%)
 * Likes:    344
 * Dislikes: 0
 * Total Accepted:    115.4K
 * Total Submissions: 162.1K
 * Testcase Example:  '[3,1,2,4]'
 *
 * 给你一个整数数组 nums，将 nums 中的的所有偶数元素移动到数组的前面，后跟所有奇数元素。
 * 
 * 返回满足此条件的 任一数组 作为答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,1,2,4]
 * 输出：[2,4,3,1]
 * 解释：[4,2,3,1]、[2,4,1,3] 和 [4,2,1,3] 也会被视作正确答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 5000
 * 0 <= nums[i] <= 5000
 * 
 * 
 */
#include <stdlib.h>
#include <string.h>

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 创建数组 ans ，长度与 nums 一致
 * 设置两个索引变量
 * e 从 0 开始递增，指向 ans 的最后一个偶数
 * o 从 nums_size - 1 开始递减，指向 ans 第一个奇数
 */
int *sortArrayByParity(int* nums, int nums_size, int* return_size){

        int i = 0, j = nums_size - 1;
        while(i < j) {
                while(i < j && (nums[j] & 1) == 1) j--;
                while(i < j && (nums[i] & 1) == 0) i++;
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
        }

        int *ans = malloc(sizeof(int) * nums_size);
        *return_size = nums_size;
        memcpy(ans, nums, sizeof(int) * nums_size);

        return ans;
}
// @lc code=end


