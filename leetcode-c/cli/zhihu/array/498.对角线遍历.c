/*
 * @lc app=leetcode.cn id=498 lang=c
 *
 * [498] 对角线遍历
 *
 * https://leetcode.cn/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (55.67%)
 * Likes:    428
 * Dislikes: 0
 * Total Accepted:    101.1K
 * Total Submissions: 181.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,4,7,5,3,6,8,9]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：mat = [[1,2],[3,4]]
 * 输出：[1,2,3,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * -10^5 <= mat[i][j] <= 10^5
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * findDiagonalOrder(int **mat, int mat_size,
                        int *mat_col_size, int *return_size)
{
        int m = mat_size;
        int n = mat_col_size[0];

        int *result = malloc(sizeof(int) * m * n);
        *return_size = m * n;

        int k = 0;
        for (int i = 0; i < m + n - 1; i++) {
                if (i % 2) {
                        int x = i < n ? 0 : i - n + 1;
                        int y = i < n ? i : n - 1;
                        while(x < m && y >= 0) {
                                result[k++] = mat[x][y];
                                x++;
                                y--;
                        }
                } else {
                        int x = i < m ? i : m - 1;
                        int y = i < m ? 0 : i - m + 1;
                        while(x >= 0 && y < n) {
                                result[k++] = mat[x][y];
                                x--;
                                y++;
                        }
                }
        }

        return result;
}
// @lc code=end


