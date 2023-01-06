/*
 * @lc app=leetcode.cn id=645 lang=c
 *
 * [645] 错误的集合
 *
 * https://leetcode.cn/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (40.61%)
 * Likes:    304
 * Dislikes: 0
 * Total Accepted:    96.8K
 * Total Submissions: 238.7K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字
 * 复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且有一个数字
 * 重复 。
 * 
 * 给定一个数组 nums 代表了集合 S 发生错误后的结果。
 * 
 * 请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,2,4]
 * 输出：[2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1]
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * 1 
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 1. nums 按从小到大排序
 * 2. 遍历 nums 
 *   2.1 如果 a,a+1 相等，则 a 为重复的数字
 *   2.2 如果 a,a+1 相差大于1，则 a,a+1 之间的数字为缺失的数字
 * 3. 如果 nums[nums_size - 1] != nums_size 则表示 n 为缺失的数字
 *
 */
int* findErrorNums(int *nums, int nums_size, int *return_size)
{
        int n = nums_size;
        qsort(nums, n, sizeof(int), cmp);

        int prev = 0;
        int *err_nums = malloc(sizeof(int) * 2);
        for (int i = 0; i < n; i++) {
                int curr = nums[i];
                if (curr == prev) {
                        err_nums[0] = prev;
                } else if (curr - prev > 1) {
                        err_nums[1] = prev + 1;
                }
                prev = curr;
        }

        if (nums[n - 1] != n) {
                err_nums[1] = n;
        }

        *return_size = 2;
        return err_nums;
}
// @lc code=end


