/*
 * @lc app=leetcode.cn id=697 lang=c
 *
 * [697] 数组的度
 *
 * https://leetcode.cn/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (59.63%)
 * Likes:    455
 * Dislikes: 0
 * Total Accepted:    85.3K
 * Total Submissions: 143.1K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * 给定一个非空且只包含非负数的整数数组 nums，数组的 度 的定义是指数组里任一
 * 元素出现频数的最大值。
 * 
 * 你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其
 * 长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,2,3,1]
 * 输出：2
 * 解释：
 * 输入数组的度是 2 ，因为元素 1 和 2 的出现频数最大，均为 2 。
 * 连续子数组里面拥有相同度的有如下所示：
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * 最短连续子数组 [2, 2] 的长度为 2 ，所以返回 2 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,2,3,1,4,2]
 * 输出：6
 * 解释：
 * 数组的度是 3 ，因为元素 2 重复出现 3 次。
 * 所以 [2,2,3,1,4,2] 是最短子数组，因此返回 6 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums.length 在 1 到 50,000 范围内。
 * nums[i] 是一个在 0 到 49,999 范围内的整数。
 * 
 * 
 */
#include "include/uthash.h"

// @lc code=start

typedef struct {
        int key;
        int freq;
        int start, end;
        UT_hash_handle hh;
} hash_map;

static void free_hash_map(hash_map *map)
{
        hash_map *node, *tmp;
        HASH_ITER(hh, map, node, tmp) {
                HASH_DEL(map, node);
                free(node);
        }
}

/**
 * 1. 创建计数用的哈希表 map， 遍历数组 nums, 设当前元素为 a
 *   1.1 如果 a 不在哈希表中，则将 a 插入到 map 中，设置 freq、start 和 end
 *   1.2 如果 a 在哈希表中，则将 a 的频数加一，更新 end 为当前索引
 * 2. 在 1 的过程中，设置遍历 max_freq, max_num 分别记录最大频数和对应
 *    的数字
 *   2.1 当遇到一个元素的频数与 max_freq 相等时，则需要比较两个元素的最短
 *       连续子数组长度，取长度较小这者为 max_num
 * 3. nums 遍历结束之后，得到一个能知道最大频数 max_num，从哈希表中取出
 *    改元素的起始和结束位置
 *
 * T(n): O(n)
 * S(n): O(n)
 */
int findShortestSubArray(int* nums, int nums_size)
{

        hash_map *map = NULL;
        int max_freq = 0, max_num = 0;
        for (int i = 0; i < nums_size; i++) {
                hash_map *tmp;
                HASH_FIND_INT(map, &nums[i], tmp);
                if (tmp == NULL) {
                        tmp = malloc(sizeof(hash_map));
                        tmp->key   = nums[i];
                        tmp->freq  = 1;
                        tmp->start = i;
                        tmp->end   = i; // end 不初始化可能是个随机数
                        HASH_ADD_INT(map, key, tmp);
                } else {
                        tmp->freq += 1;
                        tmp->end = i;
                }

                if (max_freq < tmp->freq) {
                        max_freq = tmp->freq;
                        max_num  = tmp->key;
                } if (max_freq == tmp->freq) {
                        hash_map *t2;
                        HASH_FIND_INT(map, &max_num, t2);
                        int len1 = tmp->end - tmp->start + 1;
                        int len2 = t2->end - t2->start + 1;
                        if (len1 < len2) {
                                max_num = tmp->key;
                        }
                }
        }

        hash_map *tmp;
        HASH_FIND_INT(map, &max_num, tmp);

        int ans = tmp->end - tmp->start + 1;
        
        free_hash_map(map);

        return ans;
}
// @lc code=end


