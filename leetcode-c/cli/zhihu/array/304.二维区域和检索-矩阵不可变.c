/*
 * @lc app=leetcode.cn id=304 lang=c
 *
 * [304] 二维区域和检索 - 矩阵不可变
 *
 * https://leetcode.cn/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (60.90%)
 * Likes:    463
 * Dislikes: 0
 * Total Accepted:    115.8K
 * Total Submissions: 190K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
  '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * 给定一个二维矩阵 matrix，以下类型的多个请求：
 * 
 * 
 * 计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。
 * 
 * 
 * 实现 NumMatrix 类：
 * 
 * 
 * NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
 * int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1)
 * 、右下角 (row2, col2) 所描述的子矩阵的元素 总和 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: 
 * ["NumMatrix","sumRegion","sumRegion","sumRegion"]
 * 
 * [[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
 * 输出: 
 * [null, 8, 11, 12]
 * 
 * 解释:
 * NumMatrix numMatrix = new
 * NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]);
 * numMatrix.sumRegion(2, 1, 4, 3); // return 8 (红色矩形框的元素总和)
 * numMatrix.sumRegion(1, 1, 2, 2); // return 11 (绿色矩形框的元素总和)
 * numMatrix.sumRegion(1, 2, 2, 4); // return 12 (蓝色矩形框的元素总和)
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * -10^5 <= matrix[i][j] <= 10^5
 * 0 <= row1 <= row2 < m
 * 0 <= col1 <= col2 < n
 * 最多调用 10^4 次 sumRegion 方法
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start

/*
 * 初始化时对数组计算前缀和，每次检索即可在 O(1) 的时间内得到结果。
 * 可以将第 303 题的做法应用于这道题，初始化时对矩阵的每一行计算前缀和，
 * 检索时对二维区域中的每一行计算子数组和，然后对每一行的子数组和计算总和
 */

typedef struct {
        int **sum_mat;
        int mat_size;
} NumMatrix;

static int *sum_row(int *num, int size)
{
        int *sum = malloc(sizeof(int) * (size + 1));
        sum[0] = 0;
        for (int i = 0; i < size; i++)
                sum[i + 1] = sum[i] + num[i];

        return sum;
}

static int sum_range(int *num, int i, int j)
{
        return num[j + 1] - num[i];
}

NumMatrix* numMatrixCreate(int **matrix, int matrix_size, int *matrix_col_size)
{
        NumMatrix *num_matrix = malloc(sizeof(NumMatrix));

        num_matrix->mat_size = matrix_size;
        num_matrix->sum_mat = malloc(sizeof(int *) * matrix_size);
        int col_size = matrix_col_size[0];
        for (int i = 0; i < matrix_size; i++)
                num_matrix->sum_mat[i] = sum_row(matrix[i], col_size);

        return num_matrix;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2)
{
        int result = 0;
        for (int i = row1; i <= row2; i++)
                result += sum_range(obj->sum_mat[i], col1, col2);

        return result;
}

void numMatrixFree(NumMatrix* obj)
{
        for (int i = 0; i < obj->mat_size; i++)
                free(obj->sum_mat[i]);
        free(obj->sum_mat);
        free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/
// @lc code=end


