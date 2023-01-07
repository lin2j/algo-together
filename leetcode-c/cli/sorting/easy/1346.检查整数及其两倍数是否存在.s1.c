/*
 * @lc app=leetcode.cn id=1346 lang=c
 *
 * [1346] 检查整数及其两倍数是否存在
 *
 * https://leetcode.cn/problems/check-if-n-and-its-double-exist/description/
 *
 * algorithms
 * Easy (42.45%)
 * Likes:    81
 * Dislikes: 0
 * Total Accepted:    31.7K
 * Total Submissions: 74.7K
 * Testcase Example:  '[10,2,5,3]'
 *
 * 给你一个整数数组 arr，请你检查是否存在两个整数 N 和 M，
 * 满足 N 是 M 的两倍（即，N = 2 * M）。
 * 
 * 更正式地，检查是否存在两个下标 i 和 j 满足：
 * 
 * 
 * i != j
 * 0 <= i, j < arr.length
 * arr[i] == 2 * arr[j]
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [10,2,5,3]
 * 输出：true
 * 解释：N = 10 是 M = 5 的两倍，即 10 = 2 * 5 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [7,1,14,11]
 * 输出：true
 * 解释：N = 14 是 M = 7 的两倍，即 14 = 2 * 7 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [3,1,7,11]
 * 输出：false
 * 解释：在该情况下不存在 N 和 M 满足 N = 2 * M 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= arr.length <= 500
 * -10^3 <= arr[i] <= 10^3
 * 
 * 
 */

#include "include/uthash.h"
#include <stdbool.h>

// @lc code=start

typedef struct {
        int key;
        int val;
        UT_hash_handle hh;
} hash_set;

static void free_hash_set(hash_set **set)
{
        hash_set *node, *tmp;
        HASH_ITER(hh, *set, node, tmp) {
                HASH_DEL(*set, node);
                free(node);
        }
}

/**
 * 1. 将所有的元素放入哈希表中
 * 2. 遍历 arr，设当前遍历的元素为 a
 * 3. 在哈希表中查找 2*a
 *   3.1 如果存在则返回 true
 * 4. 遍历结束依然没有找到，则返回 false
 *
 * Tc: O(n)
 * Sc: O(n)
 */
bool checkIfExist(int *arr, int arr_size){

        hash_set *set = NULL, *tmp;
        for (int i = 0; i < arr_size; i++) {
                int x = arr[i];
                HASH_FIND_INT(set, &x, tmp);
                if (tmp == NULL) {
                        tmp = malloc(sizeof(hash_set));
                        tmp->key = x;
                        tmp->val = i;
                        HASH_ADD_INT(set, key, tmp);
                }
        }

        for (int i = 0; i < arr_size; i++) {
                int a = 2 * arr[i];
                HASH_FIND_INT(set, &a, tmp);
                if (tmp != NULL && tmp->val != i)
                        return true;
        }

        free_hash_set(&set);

        return false;
}
// @lc code=end


