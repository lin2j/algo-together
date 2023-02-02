/*
 * @lc app=leetcode.cn id=48 lang=c
 *
 * [48] 旋转图像
 *
 * https://leetcode.cn/problems/rotate-image/description/
 *
 * algorithms
 * Medium (74.57%)
 * Likes:    1545
 * Dislikes: 0
 * Total Accepted:    414.3K
 * Total Submissions: 555.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 * 
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[7,4,1],[8,5,2],[9,6,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 * 
 * 
 * 
 * 
 */

// @lc code=start


/*
 * 情况一：顺时针转 90 度：先转置再左右镜像
 * 1 2 3               7 4 1
 * 4 5 6               8 5 2
 * 7 8 9               9 6 3
 * 情况二：顺时针转 180 度:先上下镜像，再左右镜像（先左右再上下也可）
 * 1 2 3               9 8 7
 * 4 5 6               6 5 4
 * 7 8 9               3 2 1
 * 情况三：顺时针转 270 度：先转置再上下镜像
 * 1 2 3              3 6 9
 * 4 5 6              2 5 8
 * 7 8 9              1 4 7
 */
void rotate(int **matrix, int matrix_size, int *matrix_col_size)
{
        int n = matrix_size;

        // 转置
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                        int tmp = matrix[i][j];
                        matrix[i][j] = matrix[j][i];
                        matrix[j][i] = tmp;
                }
        }

        // 左右镜像
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n / 2; j++) {
                        int tmp = matrix[i][n - j - 1];
                        matrix[i][n - j - 1] = matrix[i][j];
                        matrix[i][j] = tmp;
                }
        }
}
// @lc code=end


