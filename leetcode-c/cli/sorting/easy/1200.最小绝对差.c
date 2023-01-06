/*
 * @lc app=leetcode.cn id=1200 lang=c
 *
 * [1200] 最小绝对差
 *
 * https://leetcode.cn/problems/minimum-absolute-difference/description/
 *
 * algorithms
 * Easy (72.61%)
 * Likes:    134
 * Dislikes: 0
 * Total Accepted:    55.5K
 * Total Submissions: 76.4K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你个整数数组 arr，其中每个元素都 不相同。
 * 
 * 请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
 * 
 * 每对元素对 [a,b] 如下：
 * 
 * 
 * a , b 均为数组 arr 中的元素
 * a < b
 * b - a 等于 arr 中任意两个元素的最小绝对差
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：arr = [4,2,1,3]
 * 输出：[[1,2],[2,3],[3,4]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：arr = [1,3,6,10,15]
 * 输出：[[1,3]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：arr = [3,8,-10,23,19,-4,-14,27]
 * 输出：[[-14,-10],[19,23],[23,27]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= arr.length <= 10^5
 * -10^6 <= arr[i] <= 10^6
 * 
 * 
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// @lc code=start


int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * 
 * 1. 将 arr 进行排序，那么最小绝对值一定会出现在相邻元素
 * 2. 遍历 arr 将最小绝对值找出并存储为 best
 * 3. 再一次遍历 arr，将相邻绝对值为 best 的元素存储在答案之中
 */
int ** minimumAbsDifference(int *arr, int arr_size,
                            int *return_size, int **return_column_sizes){
        qsort(arr, arr_size, sizeof(int), cmp);

        int size = 0;
        int best = INT32_MAX;
        int n = arr_size - 1;
        for (int i = 0; i < n; i++) {
                int delta = abs(arr[i] - arr[i + 1]);
                if (best > delta) {
                        best = delta;
                        size = 1;
                } else if (best == delta) {
                        size++;
                }
        }

        int pos = 0;
        int **result = malloc(sizeof(int *) * size);
        for (int i = 0; i < n; i++) {
                int delta = abs(arr[i] - arr[i + 1]);
                if (delta == best) {
                        result[pos] = malloc(sizeof(int) * 2);
                        result[pos][0] = arr[i];
                        result[pos][1] = arr[i + 1];
                        pos++;
                }
        }

        *return_size = pos;
        *return_column_sizes = (int *)malloc(sizeof(int) * pos);
        for (int i = 0; i < pos; i++)
                (*return_column_sizes)[i] = 2;

        return result;
}
// @lc code=end


