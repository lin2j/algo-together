/*
 * @lc app=leetcode.cn id=73 lang=c
 *
 * [73] 矩阵置零
 *
 * https://leetcode.cn/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (62.71%)
 * Likes:    828
 * Dislikes: 0
 * Total Accepted:    230.5K
 * Total Submissions: 367.5K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，
 * 则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：[[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个仅使用常量空间的解决方案吗？
 * 
 * 
 */
#include <stdlib.h>
#include <string.h>

// @lc code=start


/*
 * 创建 row 和 col 两个数组，分别用来表示哪一行/列存在 0，若行/列 i/j 存在 0
 * 则 row[i] 和 col[j] 为 0
 *
 * 遍历 row，若 row[i] 为 0，则 matrix[i][*] 全为 0
 * 遍历 col, 若 col[j] 为 0，则 matrix[*][j] 全为 0
 *
 * T(n): O(MN)，需要遍历二维数组的每个元素
 * S(n): O(M + N)
 */
void setZeroes(int **matrix, int matrix_size, int *matrix_col_size)
{
        int m = matrix_size;
        int n = matrix_col_size[0];

        int row[m], col[n];
        memset(row, 1, sizeof(row));
        memset(col, 1, sizeof(col));

        for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                        if (matrix[i][j] == 0) {
                                row[i] = 0;
                                col[j] = 0;
                        }

        for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                        if (row[i] == 0 || col[j] == 0)
                                matrix[i][j] = 0;

}
// @lc code=end


