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
 * 集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某
 * 一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数
 * 字 并且有一个数字重复 。
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

static inline int int_cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 题目没有说明数组是递增的，因此需要先将数组排序
 *
 * 对于前后两个数 a 和 a+1, 如果二者的差 d 等于 0，则表示 a 是重复数字，
 * 如果 d 等于 2，则表示 a 和 a+1 之间的数是缺失的数。
 *
 * 如果数组的最后一个数字不是 n，那么遍历的时候无法发现，因此遍历结束之后
 * 再进行一次判断
 */
int * findErrorNums(int *nums, int nums_size, int *return_size)
{
        *return_size = 2;
        int *err_nums = malloc(sizeof(int) * 2);

        qsort(nums, nums_size, sizeof(int), int_cmp);

        int prev = 0;
        for (int i = 0; i < nums_size; i++) {
                int d = nums[i] - prev;
                if (d == 0) 
                        err_nums[0] = prev;
                if (d > 1)
                        err_nums[1] = prev + 1;
                prev = nums[i];
        }

        if (nums[nums_size - 1] != nums_size) {
                err_nums[1] = nums_size;
        }

        return err_nums;
}
// @lc code=end


