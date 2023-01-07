/*
 * @lc app=leetcode.cn id=349 lang=c
 *
 * [349] 两个数组的交集
 *
 * https://leetcode.cn/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (74.35%)
 * Likes:    686
 * Dislikes: 0
 * Total Accepted:    384.1K
 * Total Submissions: 516.6K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 
 * 唯一 的。我们可以 不考虑输出结果的顺序 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 * 
 * 
 */

#include <stdlib.h>
#include "include/uthash.h"

// @lc code=start

typedef struct unordered_set {
        int key;
        UT_hash_handle hh;
} set;

static set * find(set **table, int key)
{
        set *tmp;
        HASH_FIND_INT(*table, &key, tmp);
        return tmp;
}

static void insert(set **table, int ikey)
{
        set * tmp = find(table, ikey);
        if (tmp != NULL) return;
        tmp = malloc(sizeof(set));
        tmp->key = ikey;
        HASH_ADD_INT(*table, key, tmp);
}

static int * get_intersection(set **set1, set **set2, int *return_size) 
{
        int count_s1 = HASH_COUNT(*set1);
        int count_s2 = HASH_COUNT(*set2);

        if (count_s1 > count_s2) {
                return get_intersection(set2, set1, return_size);           
        }

        int *intersection = malloc(sizeof(int) * count_s1);
        set *s, *tmp;
        HASH_ITER(hh, *set1, s, tmp) {
                if (find(set2, s->key))
                        intersection[(*return_size)++] = s->key;
        }
        return intersection;
}

static void free_set(set **table)
{
        set *node, *tmp;
        HASH_ITER(hh, *table, node, tmp) {
                HASH_DEL(*table, node);
                free(node);
        }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 使用哈希表用来判断元素是否重复
 * 1. 将 nums1 和 nums2 的元素分别放入 set1 和 set2 中
 * 2. 遍历 set1，如果 set1 的元素在 set2 中存在，那么
 *    将该元素放入 intersection 数组中
 *
 */
int * intersection(int *nums1, int nums1_size,
                   int *nums2, int nums2_size, 
                   int *return_size)
{
        *return_size = 0;
        set *set1 = NULL, *set2 = NULL;

        for (int i = 0; i < nums1_size; i++)
                insert(&set1, nums1[i]);

        for (int i = 0; i < nums2_size; i++)
                insert(&set2, nums2[i]);

        int *intersection = get_intersection(&set1, &set2, return_size);

        free_set(&set1);
        free_set(&set2);
        set1 = NULL;
        set2 = NULL;

        return intersection;
}
// @lc code=end


