/*
 * @lc app=leetcode.cn id=118 lang=c
 *
 * [118] 杨辉三角
 *
 * https://leetcode.cn/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (75.50%)
 * Likes:    897
 * Dislikes: 0
 * Total Accepted:    375K
 * Total Submissions: 496.4K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
 * 
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: numRows = 1
 * 输出: [[1]]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int ** generate(int num_rows, int *return_size, int **return_column_sizes)
{
        *return_size = 0;
        int **result = malloc(sizeof(int *) * num_rows);
        *return_column_sizes = malloc(sizeof(int *) * num_rows);

        for (int i = 0; i < num_rows; i++) {
                (*return_column_sizes)[i] = i + 1;
                int *row = malloc(sizeof(int) * (i + 1));
                result[(*return_size)++] = row;
                result[i][0] = result[i][i] = 1;
                for (int j = 1; j < i; j++) {
                        result[i][j] = result[i-1][j] + result[i-1][j-1];
                }
        }

        return result;
}
// @lc code=end


