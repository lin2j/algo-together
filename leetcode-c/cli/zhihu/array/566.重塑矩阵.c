/*
 * @lc app=leetcode.cn id=566 lang=c
 *
 * [566] 重塑矩阵
 *
 * https://leetcode.cn/problems/reshape-the-matrix/description/
 *
 * algorithms
 * Easy (65.51%)
 * Likes:    373
 * Dislikes: 0
 * Total Accepted:    133.1K
 * Total Submissions: 203.3K
 * Testcase Example:  '[[1,2],[3,4]]\n1\n4'
 *
 * 在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x
 * c）的新矩阵，但保留其原始数据。
 * 
 * 给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。
 * 
 * 重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。
 * 
 * 如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：mat = [[1,2],[3,4]], r = 1, c = 4
 * 输出：[[1,2,3,4]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：mat = [[1,2],[3,4]], r = 2, c = 4
 * 输出：[[1,2],[3,4]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * -1000 <= mat[i][j] <= 1000
 * 1 <= r, c <= 300
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
int ** matrixReshape(int **mat, int mat_size, int *mat_col_size,
                     int r, int c, int *return_size, int **return_column_sizes)
{
        int m = mat_size;
        int n = mat_col_size[0];

        if (r * c != m * n) {
                *return_size = m;
                *return_column_sizes = malloc(sizeof(int) * m);
                for (int i = 0; i < m; i++)
                        (*return_column_sizes)[i] = n;
                return mat;
        }

        int **result = malloc(sizeof(int *) * r);
        *return_column_sizes = malloc(sizeof(int) * r);
        *return_size = r;
        for (int i = 0; i < r; i++) {
                result[i] = malloc(sizeof(int) * c);
                (*return_column_sizes)[i] = c;
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                        int x = cnt / c;
                        int y = cnt % c;
                        result[x][y] = mat[i][j];
                        cnt++;
                }
        }
        
        return result;
}
// @lc code=end


