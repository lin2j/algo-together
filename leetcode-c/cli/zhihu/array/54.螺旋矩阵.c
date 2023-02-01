/*
 * @lc app=leetcode.cn id=54 lang=c
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.30%)
 * Likes:    1292
 * Dislikes: 0
 * Total Accepted:    336.7K
 * Total Submissions: 683K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * spiralOrder(int **matrix, int matrix_size,
                 int *matrix_col_size, int *return_size)
{
        int len = matrix_size * matrix_col_size[0];
        int *result = malloc(sizeof(int) * len);
        *return_size = len;

        int top = 0;
        int left = 0;
        int right = matrix_col_size[0] - 1;
        int bottom = matrix_size - 1;

        int k = 0;
        while(top <= bottom && left <= right) {
                for (int i = left; i <= right; i++)
                        result[k++] = matrix[top][i];
                if (++top > bottom) break;

                for (int i = top; i <= bottom; i++)
                        result[k++] = matrix[i][right];
                if (--right < left) break;

                for (int i = right; i >= left; i--)
                        result[k++] = matrix[bottom][i];
                if (--bottom < top) break;

                for (int i = bottom; i >= top; i--)
                        result[k++] = matrix[i][left];
                if (++left > right) break;
        }

        return result;
}
// @lc code=end


