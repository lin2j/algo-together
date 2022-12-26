/*
 * @lc app=leetcode.cn id=217 lang=c
 *
 * [217] 存在重复元素
 *
 * https://leetcode.cn/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (55.67%)
 * Likes:    871
 * Dislikes: 0
 * Total Accepted:    705.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,1]'
 *
 * 给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,1]
 * 输出：true
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：false
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,1,1,3,3,4,3,2,4,2]
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */
#include <stdlib.h>
#include <stdbool.h>
#include "../include/uthash.h"

// @lc code=start

struct hash_table {
        int key;
        UT_hash_handle hh;
};

/**
 * 使用哈希表，遍历数组，将碰到的元素进行判断
 * 1. 如果该元素已经在哈希表中，说明该元素是重复的
 * 2. 如果共元素不在哈希表中，那么将该元素放到哈希表中
 */
bool containsDuplicate(int *nums, int nums_size)
{
        struct hash_table *set = NULL;
        for (int i = 0; i < nums_size; i++) {
                struct hash_table *tmp = NULL;
                HASH_FIND_INT(set, &nums[i], tmp);
                if (tmp == NULL) {
                        tmp = malloc(sizeof(struct hash_table));
                        tmp->key = nums[i];
                        HASH_ADD_INT(set, key, tmp);
                } else {
                        return true;
                }
        }
        return false;
}
// @lc code=end

