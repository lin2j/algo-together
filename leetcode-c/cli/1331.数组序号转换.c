/*
 * @lc app=leetcode.cn id=1331 lang=c
 *
 * [1331] 数组序号转换
 *
 * https://leetcode.cn/problems/rank-transform-of-an-array/description/
 *
 * algorithms
 * Easy (60.58%)
 * Likes:    124
 * Dislikes: 0
 * Total Accepted:    44.1K
 * Total Submissions: 72.8K
 * Testcase Example:  '[40,10,20,30]'
 *
 * 给你一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号。
 * 
 * 序号代表了一个元素有多大。序号编号的规则如下：
 * 
 * 
 * 序号从 1 开始编号。
 * 一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。
 * 每个数字的序号都应该尽可能地小。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [40,10,20,30]
 * 输出：[4,1,2,3]
 * 解释：40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。
 * 
 * 示例 2：
 * 
 * 输入：arr = [100,100,100]
 * 输出：[1,1,1]
 * 解释：所有元素有相同的序号。
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [37,12,28,9,100,56,80,5,12]
 * 输出：[5,3,4,2,8,6,7,1,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= arr.length <= 10^5
 * -10^9 <= arr[i] <= 10^9
 * 
 * 
 */
#include "../include/uthash.h"
#include <stdlib.h>

// @lc code=start

typedef struct {
        int key;
        int rank;
        UT_hash_handle hh;
} hash_map;

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

static void free_hash_map(hash_map **map)
{
        hash_map *node, *tmp;
        HASH_ITER(hh, *map, node, tmp) {
                HASH_DEL(*map, node);
                free(node);
        }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 1. 创建一个数组 sorted 拷贝 arr，并将 sorted 排序
 * 2. 使用哈希表记录 sorted 中每个元素的排位，遍历 sorted，
 *    设当前元素为 x，当前排位为 rank（rank 从 1 开始计算）
 *   2.1 如果哈希表中已经存在 x，则继续遍历
 *   2.2 如果哈希表中不存在 x，将 x 放入哈希表中，映射为 rank，rank++
 * 3 创建答案数组 result， 索引为 idx；遍历 arr，设当前元素为 a
 *   3.1 从哈希表获取 a 对应的排名 rank，则 result[idx++] = rank
 * 4. 返回答案数组
 *
 * Tc: O(nlogn)
 * Sc: O(n)
 */
int * arrayRankTransform(int *arr, int arr_size, int *return_size){
        int *sorted = malloc(sizeof(int) * arr_size);
        memcpy(sorted, arr, sizeof(int) * arr_size);
        qsort(sorted, arr_size, sizeof(int), cmp);

        int size = 0;
        hash_map *rank_map = NULL, *tmp;
        for (int i = 0; i < arr_size; i++) {
                int x = sorted[i];
                HASH_FIND_INT(rank_map, &x, tmp);
                if (tmp != NULL) continue;

                tmp = malloc(sizeof(hash_map));
                tmp->key = x;
                tmp->rank = ++size;
                HASH_ADD_INT(rank_map, key, tmp);
        }

        int idx = 0;
        int *result = malloc(sizeof(int) * arr_size);
        *return_size = arr_size;
        for (int i = 0; i < arr_size; i++) {
                HASH_FIND_INT(rank_map, &arr[i], tmp);
                if (tmp == NULL) continue;
                result[idx++] = tmp->rank;
        }

        free_hash_map(&rank_map);

        return result;
}
// @lc code=end


