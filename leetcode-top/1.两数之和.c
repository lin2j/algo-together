/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 *
 * https://leetcode.cn/problems/two-sum/description/
 *
 * algorithms
 * Easy (53.80%)
 * Total Accepted:    5.5M
 * Total Submissions: 10.2M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 
 * 你可以按任意顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 只会存在一个有效答案
 * 
 * 
 * 
 * 
 * 进阶：你可以想出一个时间复杂度小于 O(n^2) 的算法吗？
 * 
 */

#include <stdlib.h>
#include "uthash.h"

// @lc code=start

typedef struct {
        int key;
        int value;
        UT_hash_handle hh;
} hash_map;

static void put_map(hash_map **map, int ikey, int value)
{
        hash_map *node;
        HASH_FIND_INT(*map, &ikey, node);
        if (node == NULL) {
                node = malloc(sizeof(hash_map));
                node->key = ikey;
                node->value = value;
                HASH_ADD_INT(*map, key, node);
        } else {
                node->value = value;
        }
}

static hash_map * find_key(hash_map **map, int ikey)
{
        hash_map *node;
        HASH_FIND_INT(*map, &ikey, node);
        return node;
}

static void free_map(hash_map **map)
{
        hash_map *node, *tmp;
        HASH_ITER(hh, *map, node, tmp) {
                HASH_DEL(*map, node);
                free(node);
        }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int *nums, int nums_size, int target, int *return_size)
{
        *return_size = 0;
        int *ans = NULL;

        if (nums == NULL || nums_size == 0) return ans;

        hash_map *map = NULL, *node;
        for (int i = 0; i < nums_size; i++) {
                int key = target - nums[i];
                node = find_key(&map, key);

                if (node == NULL)
                        put_map(&map, nums[i], i);
                else {
                        ans = malloc(sizeof(int) * 2);
                        ans[0] = node->value;
                        ans[1] = i;

                        *return_size = 2;
                }
        }

        free_map(&map);
        
        return ans;
}

// @lc code=end


