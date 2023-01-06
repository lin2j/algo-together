/*
 * @lc app=leetcode.cn id=594 lang=c
 *
 * [594] 最长和谐子序列
 *
 * https://leetcode.cn/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (56.23%)
 * Likes:    349
 * Dislikes: 0
 * Total Accepted:    76.2K
 * Total Submissions: 135.6K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * 和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。
 * 
 * 现在，给你一个整数数组 nums ，请你在所有可能的子序列中找到最长的和谐子序列的长度。
 * 
 * 数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,2,2,5,2,3,7]
 * 输出：5
 * 解释：最长的和谐子序列是 [3,2,2,2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,1,1,1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^9 
 * 
 * 
 */

#include <stdlib.h>
#include "../include/uthash.h"

// @lc code=start

#define MAX(a, b) (a) > (b) ? (a) : (b)

typedef struct {
        int key;
        int value;
        UT_hash_handle hh;
} hash_map;

static void insert_and_count(hash_map **map, int ikey)
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
        hash_map *node;
        HASH_FIND_INT(*map, &ikey, node);
        return node != NULL ? node->value : 0;
}

static void free_hash_map(hash_map **map)
{
        hash_map *node, *tmp;
        HASH_ITER(hh, *map, node, tmp) {
                HASH_DEL(*map, node);
                free(node);
        }
        free(*map);
}

/*
 * 1. 使用哈希表统计每个数字出现的次数
 * 2. 遍历 nums，设当前数字为 a，则从哈希表中求出 a+1 出现的次数
 *   2.1 如果 a+1 出现的次数为 0，则继续
 *   2.2 如果 a+1 出现的次数不为 0，则将 a 出现的次数与 a+1 出现的次数相加
 * 3. 统计整个过程中出现的最大次数和
 *
 */
int findLHS(int *nums, int nums_size)
{
        hash_map *map = NULL;
        for (int i = 0; i < nums_size; i++)
                insert_and_count(&map, nums[i]);

        int ans = 0;
        hash_map *node = NULL;
        for (int i = 0; i < nums_size; i++) {
                int n = nums[i];
                int count_p = get_count(&map, n + 1);
                if (count_p == 0) continue;
                ans = MAX(ans, count_p + get_count(&map, n));
        }

        free_hash_map(&map);

        return ans;
}
// @lc code=end


