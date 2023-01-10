/*
 * @lc app=leetcode.cn id=448 lang=c
 *
 * [448] 找到所有数组中消失的数字
 *
 * https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (65.86%)
 * Likes:    1137
 * Dislikes: 0
 * Total Accepted:    251.7K
 * Total Submissions: 382.2K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所
 * 有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,3,2,7,8,2,3,1]
 * 输出：[5,6]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1]
 * 输出：[2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 
 * 1 
 * 
 * 
 * 进阶：你能在不使用额外空间且时间复杂度为 O(n) 的情况下解决这个问题吗? 
 * 你可以假定返回的数组不算在额外空间内。
 * 
 */
#include "include/uthash.h"
#include <stdlib.h>

// @lc code=start

typedef struct {
        int key;
        UT_hash_handle hh;
} hash_set;

static void free_hash_set(hash_set *set)
{
        hash_set *node, *tmp;
        HASH_ITER(hh, set, node, tmp) {
                HASH_DEL(set, node);
                free(node);
        }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 1. 遍历数组 nums，将元素放入哈希表中
 * 2. n 减去哈希表的元素个数 count，则为缺失的元素个数
 * 3. 遍历 [1, n] 之间的数字，如果没有出现在哈希表中，则为缺失的数字
 *
 * T(n): O(n)
 * S(n): O(n)
 */
int* findDisappearedNumbers(int* nums, int nums_size, int* return_size)
{
        hash_set *set = NULL, *tmp;

        for (int i = 0; i < nums_size; i++) {
                HASH_FIND_INT(set, &nums[i], tmp);
                if (tmp != NULL) continue;

                tmp = malloc(sizeof(hash_set));
                tmp->key = nums[i];
                HASH_ADD_INT(set, key, tmp);
        }

        int count = HASH_COUNT(set);
        int len = nums_size - count;

        *return_size = 0;
        int *result = malloc(sizeof(int) * len);
        for (int i = 1; i <= nums_size; i++) {
                int j = i;
                HASH_FIND_INT(set, &j, tmp);
                if (tmp == NULL)
                        result[(*return_size)++] = i;
        }

        free_hash_set(set);

        return result;
}
// @lc code=end


