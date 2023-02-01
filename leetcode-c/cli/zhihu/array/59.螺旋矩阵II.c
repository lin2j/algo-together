/*
 * @lc app=leetcode.cn id=59 lang=c
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (74.35%)
 * Likes:    921
 * Dislikes: 0
 * Total Accepted:    275.6K
 * Total Submissions: 370.8K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
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
int ** generateMatrix(int n, int * return_size, int **return_column_sizes)
{
        int **result = malloc(sizeof(int *) * n);
        *return_column_sizes = malloc(sizeof(int) * n);
        *return_size = n;
        for (int i = 0; i < n; i++) {
                result[i] = malloc(sizeof(int) * n);
                (*return_column_sizes)[i] = n;
        }

        int top = 0;
        int left = 0;
        int bottom = n - 1;
        int right = n - 1;
        
        int k = 1;
        while(top <= bottom && left <= right) {
                for (int i = left; i <= right; i++)
                        result[top][i] = k++;
                if (++top > bottom) break;

                for (int i = top; i <= bottom; i++)
                        result[i][right] = k++;
                if (--right < left) break;

                for (int i = right; i >= left; i--)
                        result[bottom][i] = k++;
                if (--bottom < top) break;

                for (int i = bottom; i >= top; i--)
                        result[i][left] = k++;
                if (++left > right) break;
        }

        return result;
}
// @lc code=end


