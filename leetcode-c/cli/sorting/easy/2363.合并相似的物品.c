/*
 * @lc app=leetcode.cn id=2363 lang=c
 *
 * [2363] 合并相似的物品
 *
 * https://leetcode.cn/problems/merge-similar-items/description/
 *
 * algorithms
 * Easy (76.63%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    7.6K
 * Total Submissions: 9.9K
 * Testcase Example:  '[[1,1],[4,5],[3,8]]\n[[3,1],[1,5]]'
 *
 * 给你两个二维整数数组 items1 和 items2 ，表示两个物品集合。
 * 每个数组 items 有以下特质：
 *
 * items[i] = [valuei, weighti] 其中 valuei 表示第 i 件物品的 价值 ，
 * weighti 表示第 i 件物品的 重量。
 *
 * items 中每件物品的价值都是 唯一的 。
 * 
 * 
 * 请你返回一个二维数组 ret，其中 ret[i] = [valuei, weighti]， 
 * weighti 是所有价值为 valuei 物品的 重量之和
 * 。
 * 
 * 注意：ret 应该按价值 升序 排序后返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
 * 输出：[[1,6],[3,9],[4,5]]
 * 解释：
 * value = 1 的物品在 items1 中 weight = 1 ，在 items2 中 weight = 5 ，总重量为 1 + 5 = 6 。
 * value = 3 的物品再 items1 中 weight = 8 ，在 items2 中 weight = 1 ，总重量为 8 + 1 = 9 。
 * value = 4 的物品在 items1 中 weight = 5 ，总重量为 5 。
 * 所以，我们返回 [[1,6],[3,9],[4,5]] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：items1 = [[1,1],[3,2],[2,3]], items2 = [[2,1],[3,2],[1,3]]
 * 输出：[[1,4],[2,4],[3,4]]
 * 解释：
 * value = 1 的物品在 items1 中 weight = 1 ，在 items2 中 weight = 3 ，总重量为 1 + 3 = 4 。
 * value = 2 的物品在 items1 中 weight = 3 ，在 items2 中 weight = 1 ，总重量为 3 + 1 = 4 。
 * value = 3 的物品在 items1 中 weight = 2 ，在 items2 中 weight = 2 ，总重量为 2 + 2 = 4 。
 * 所以，我们返回 [[1,4],[2,4],[3,4]] 。
 * 
 * 示例 3：
 * 
 * 
 * 输入：items1 = [[1,3],[2,2]], items2 = [[7,1],[2,2],[1,4]]
 * 输出：[[1,7],[2,4],[7,1]]
 * 解释：
 * value = 1 的物品在 items1 中 weight = 3 ，在 items2 中 weight = 4 ，总重量为 3 + 4 = 7 。
 * value = 2 的物品在 items1 中 weight = 2 ，在 items2 中 weight = 2 ，总重量为 2 + 2 = 4 。
 * value = 7 的物品在 items2 中 weight = 1 ，总重量为 1 。
 * 所以，我们返回 [[1,7],[2,4],[7,1]] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= items1.length, items2.length <= 1000
 * items1[i].length == items2[i].length == 2
 * 1 <= valuei, weighti <= 1000
 * items1 中每个 valuei 都是 唯一的 。
 * items2 中每个 valuei 都是 唯一的 。
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

// @lc code=start

static inline int cmp(const void *a, const void *b)
{
        int **aa = (int **)a;
        int **bb = (int **)b;
        return aa[0][0] - bb[0][0];
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 *
 * 排序 + 归并
 */
int** mergeSimilarItems(int **items1, int items1_size, int *items1_col_size, 
                        int **items2, int items2_size, int *items2_col_size, 
                        int *return_size, int **return_column_sizes){

        qsort(items1, items1_size, sizeof(int *), cmp);
        qsort(items2, items2_size, sizeof(int *), cmp);

        for (int i = 0; i < items2_size; i++) {
                printf("[%d,%d]", items2[i][0], items2[i][1]);
        }

        *return_size = 0;
        int **result = malloc(sizeof(int *) * (items1_size + items2_size));
        int i = 0, j = 0;
        while(i < items1_size && j < items2_size) {
                int v1 = items1[i][0];
                int v2 = items2[j][0];
                int *tmp = malloc(sizeof(int) * 2);
                if (v1 == v2) {
                        tmp[0] = v1;
                        tmp[1] = items1[i][1] + items2[j][1];
                        result[(*return_size)++] = tmp;
                        i++, j++;
                } else if (v1 < v2){
                        tmp[0] = v1;
                        tmp[1] = items1[i][1];
                        result[(*return_size)++] = tmp;
                        i++;
                } else {
                        tmp[0] = v2;
                        tmp[1] = items2[j][1];
                        result[(*return_size)++] = tmp;
                        j++;
                }
        }

        while (i < items1_size) {
                int *tmp = malloc(sizeof(int) * 2);
                tmp[0] = items1[i][0];
                tmp[1] = items1[i][1];
                result[(*return_size)++] = tmp;
                i++;
        }

        while (j < items2_size) {
                int *tmp = malloc(sizeof(int) * 2);
                tmp[0] = items2[j][0];
                tmp[1] = items2[j][1];
                result[(*return_size)++] = tmp;
                j++;
        }

        int len = *return_size;
        *return_column_sizes = (int *)malloc(sizeof(int) * len);
        for (int i = 0; i < len; i++)
                (*return_column_sizes)[i] = 2;
        
        return result;
}
// @lc code=end


