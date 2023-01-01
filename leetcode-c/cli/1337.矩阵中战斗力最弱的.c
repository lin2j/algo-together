/*
 * @lc app=leetcode.cn id=1337 lang=c
 *
 * [1337] 矩阵中战斗力最弱的 K 行
 *
 * https://leetcode.cn/problems/the-k-weakest-rows-in-a-matrix/description/
 *
 * algorithms
 * Easy (68.94%)
 * Likes:    192
 * Dislikes: 0
 * Total Accepted:    54.4K
 * Total Submissions: 79K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]\n3'
 *
 * 给你一个大小为 m * n 的矩阵 mat，矩阵由若干军人和平民组成，分别用 1 和 0 表示。
 * 
 * 请你返回矩阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。
 * 
 * 如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，
 * 那么我们认为第 i 行的战斗力比第 j 行弱。
 * 
 * 军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：mat = 
 * [[1,1,0,0,0],
 * ⁠[1,1,1,1,0],
 * ⁠[1,0,0,0,0],
 * ⁠[1,1,0,0,0],
 * ⁠[1,1,1,1,1]], 
 * k = 3
 * 输出：[2,0,3]
 * 解释：
 * 每行中的军人数目： 
 * 行 0 -> 2 
 * 行 1 -> 4 
 * 行 2 -> 1 
 * 行 3 -> 2 
 * 行 4 -> 5 
 * 从最弱到最强对这些行排序后得到 [2,0,3,1,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：mat = 
 * [[1,0,0,0],
 * [1,1,1,1],
 * [1,0,0,0],
 * [1,0,0,0]], 
 * k = 2
 * 输出：[0,2]
 * 解释： 
 * 每行中的军人数目： 
 * 行 0 -> 1 
 * 行 1 -> 4 
 * 行 2 -> 1 
 * 行 3 -> 1 
 * 从最弱到最强对这些行排序后得到 [0,2,3,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 2 
 * 1 
 * matrix[i][j] 不是 0 就是 1
 * 
 * 
 */
#include <math.h>
#include <stddef.h> 
#include <stdlib.h> 
#include <stdbool.h>

// @lc code=start

typedef struct {
        int power;
        int row;
} pair;

int cmp(const void *a, const void *b)
{
        pair *aa = (pair *)a;
        pair *bb = (pair *)b;
        if (aa->power != bb->power)
                return aa->power - bb->power;
        else
                return aa->row - bb->row;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 
 * 定义结构体 pair 用来记录行数及对应的战斗力
 *
 * 1. 创建 pair 数组 powers
 * 2. 遍历二维数组,采用二分查找的方式，找到最后一个 1 的位置
 *   .1 如果最后一个 1 的位置为 pos，pos初始值为 -1，则战斗力为 pos+1，
 *   .2 如果找不到 1，则 pos + 1 = 0，表示战斗力为 0
 *   .3 将战斗力和行数放入 powers 数组中
 * 3. 将 powers 数组进行排序，然后取出前 k 个元素
 */
int * kWeakestRows(int **mat, int mat_size, int *mat_col_size,
                   int k, int *return_size){
        pair *powers = malloc(sizeof(pair) * mat_size);
        int m = mat_size, n = *mat_col_size;

        int idx= 0;
        for (int i = 0; i < m; i++) {
                int l = 0, r = n - 1, pos = -1;
                while(l <= r) {
                        int mid = (l + r) / 2;
                        if (mat[i][mid] == 0) {
                                r = mid - 1;
                        } else {
                                pos = mid;
                                l = mid + 1;
                        }
                }
                pair power = {.power = pos + 1, .row = i};
                powers[idx++] = power;
        }

        qsort(powers, idx, sizeof(pair), cmp);

        int *result = malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++)
                result[i] = powers[i].row;

        free(powers);

        *return_size = k;
        return result;
}
// @lc code=end


