/*
 * @lc app=leetcode.cn id=661 lang=c
 *
 * [661] 图片平滑器
 *
 * https://leetcode.cn/problems/image-smoother/description/
 *
 * algorithms
 * Easy (64.40%)
 * Likes:    192
 * Dislikes: 0
 * Total Accepted:    51K
 * Total Submissions: 79.1K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 图像平滑器 是大小为 3 x 3 的过滤器，用于对图像的每个单元格平滑处理，
 * 平滑处理后单元格的值为该单元格的平均灰度。
 * 
 * 每个单元格的  平均灰度 定义为：该单元格自身及其周围的 8 个单元格的平均值，
 * 结果需向下取整。（即，需要计算蓝色平滑器中 9 个单元格的平均值）。
 * 
 * 如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格
 * （即，需要计算红色平滑器中 4 个单元格的平均值）。
 * 
 * 
 * 
 * 给你一个表示图像灰度的 m x n 整数矩阵 img ，返回对图像的每个单元格平滑处理后的图像 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入:img = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出:[[0, 0, 0],[0, 0, 0], [0, 0, 0]]
 * 解释:
 * 对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
 * 对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
 * 对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: img = [[100,200,100],[200,50,200],[100,200,100]]
 * 输出: [[137,141,137],[141,138,141],[137,141,137]]
 * 解释:
 * 对于点 (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) =
 * 137
 * 对于点 (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) =
 * floor(141.666667) = 141
 * 对于点 (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889)
 * = 138
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * m == img.length
 * n == img[i].length
 * 1 <= m, n <= 200
 * 0 <= img[i][j] <= 255
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
int ** imageSmoother(int **img, int img_size, int* img_col_size,
                     int *return_size, int **return_column_sizes)
{
        int m = img_size;
        int n = img_col_size[0];

        *return_size = 0;
        int **result = malloc(sizeof(int *) * m);
        *return_column_sizes = malloc(sizeof(int *) * m);

        for (int i = 0; i < m; i++) {
                result[i] = malloc(sizeof(int) * n);
                (*return_column_sizes)[i] = n;
                for (int j = 0; j < n; j++) {
                        int num = 0;
                        int sum = 0;
                        for (int x = i - 1; x <= i + 1; x++) {
                                for (int y = j - 1; y <= j + 1; y++) {
                                        if (x >= 0 && y >= 0 && x < m && y < n) {
                                                num++;
                                                sum += img[x][y];
                                        }
                                }
                        }
                        result[i][j] = sum / num;
                }
        }
        *return_size = m;
        return result;
}
// @lc code=end


