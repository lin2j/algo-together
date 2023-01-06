/*
 * @lc app=leetcode.cn id=645 lang=c
 *
 * [645] 错误的集合
 *
 * https://leetcode.cn/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (40.61%)
 * Likes:    304
 * Dislikes: 0
 * Total Accepted:    96.8K
 * Total Submissions: 238.7K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字
 * 复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且有一个数字
 * 重复 。
 * 
 * 给定一个数组 nums 代表了集合 S 发生错误后的结果。
 * 
 * 请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,2,4]
 * 输出：[2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1]
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * 1 
 * 
 * 
 */
#include <stdlib.h>
#include "../include/uthash.h"

// @lc code=start

typedef struct {
        int key;
        int value;
        UT_hash_handle hh;
} hash_map;

static void add_and_count(hash_map **map, int ikey)
{
        hash_map *tmp;
        HASH_FIND_INT(*map, &ikey, tmp);
        if (tmp == NULL) {
                tmp = malloc(sizeof(hash_map));
                tmp->key = ikey;
                tmp->value = 0;
                HASH_ADD_INT(*map, key, tmp);
        }
        tmp->value += 1;
}

static int get_count(hash_map **map, int ikey)
{
        hash_map *tmp;
        HASH_FIND_INT(*map, &ikey, tmp);
        return tmp == NULL ? 0 : tmp->value;
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
 * 使用哈希表统计数字出现的次数，则重复数字的次数为2，缺失数字的次数为0
 */
int* findErrorNums(int *nums, int nums_size, int *return_size)
{
        hash_map *map = NULL;
        for (int i = 0; i < nums_size; i++)
                add_and_count(&map, nums[i]);

        *return_size = 2;
        int *ans = malloc(sizeof(int) * 2);
        for (int i = 0; i <= nums_size; i++) {
                int c = get_count(&map, i);
                if (c == 2) {
                        ans[0] = i;
                } else if (c == 0) {
                        ans[1] = i;
                }
        }

        free_hash_map(&map);

        return ans;
}
// @lc code=end


