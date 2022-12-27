/*
 * @lc app=leetcode.cn id=350 lang=c
 *
 * [350] 两个数组的交集 II
 *
 * https://leetcode.cn/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (56.77%)
 * Likes:    874
 * Dislikes: 0
 * Total Accepted:    431K
 * Total Submissions: 759.2K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给你两个整数数组 nums1 和 nums2，请你以数组形式返回两数组的交集。
 * 返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致
 * （如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2,2]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[4,9]
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
 * 
 * 
 * 进阶：
 * 
 * 
 * 如果给定的数组已经排好序呢？你将如何优化你的算法？
 * 如果 nums1 的大小比 nums2 小，哪种方法更优？
 * 如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
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

static hash_map * find(hash_map **map, int ikey)
{
        hash_map *tmp;
        HASH_FIND_INT(*map, &ikey, tmp);
        return tmp;
}

static int add_key(hash_map **map, int ikey)
{
        int value;
        hash_map *tmp = find(map, ikey);
        if (tmp == NULL) {
                tmp = malloc(sizeof(hash_map));
                tmp->key = ikey;
                tmp->value = 1;
                HASH_ADD_INT(*map, key, tmp);
                value = 1;
        } else {
                tmp->value += 1;
                value = tmp->value;
        }
        return value;
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
 * 使用哈希表
 * 1. 遍历 nums1 并在哈希表记录各个数字出现的次数
 * 2. 遍历 nums2 并查找哈希表中是否有该数字
 *      2.1 如果存在该数字，则哈希表中该数字的计数减一，
 *          将该数字放入 intersection
 *      2.2 如果不存在该数字，则继续往前遍历
 * 3. 遍历完 nums2 ，整个过程结束
 *
 */
int* intersect(int *nums1, int nums1_size,
               int *nums2, int nums2_size, 
               int* return_size){
        *return_size = 0;
        hash_map *map = NULL;

        for (int i = 0; i < nums1_size; i++)
                add_key(&map, nums1[i]);
        
        int size = nums1_size < nums2_size ? nums1_size : nums2_size;
        int *intersection = malloc(sizeof(int) * size);

        for (int i = 0; i < nums2_size; i++) {
                int ikey = nums2[i];
                hash_map *node = find(&map, ikey);
                if (node == NULL || node->value == 0) continue;
                intersection[(*return_size)++] = ikey; 
                node->value -= 1;
        }

        free_hash_map(&map);
        map = NULL;

        return intersection;
}
// @lc code=end


