/*
 * @lc app=leetcode.cn id=888 lang=c
 *
 * [888] 公平的糖果交换
 *
 * https://leetcode.cn/problems/fair-candy-swap/description/
 *
 * algorithms
 * Easy (63.83%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    65.1K
 * Total Submissions: 102K
 * Testcase Example:  '[1,1]\n[2,2]'
 *
 * 爱丽丝和鲍勃拥有不同总数量的糖果。给你两个数组 aliceSizes 和 bobSizes ，aliceSizes[i] 是爱丽丝拥有的第 i
 * 盒糖果中的糖果数量，bobSizes[j] 是鲍勃拥有的第 j 盒糖果中的糖果数量。
 * 
 * 两人想要互相交换一盒糖果，这样在交换之后，他们就可以拥有相同总数量的糖果。一个人拥有的糖果总数量是他们每盒糖果数量的总和。
 * 
 * 返回一个整数数组 answer，其中 answer[0] 是爱丽丝必须交换的糖果盒中的糖果的数目，answer[1]
 * 是鲍勃必须交换的糖果盒中的糖果的数目。如果存在多个答案，你可以返回其中 任何一个 。题目测试用例保证存在与输入对应的答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：aliceSizes = [1,1], bobSizes = [2,2]
 * 输出：[1,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：aliceSizes = [1,2], bobSizes = [2,3]
 * 输出：[1,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：aliceSizes = [2], bobSizes = [1,3]
 * 输出：[2,3]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：aliceSizes = [1,2,5], bobSizes = [2,4]
 * 输出：[5,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= aliceSizes.length, bobSizes.length <= 10^4
 * 1 <= aliceSizes[i], bobSizes[j] <= 10^5
 * 爱丽丝和鲍勃的糖果总数量不同。
 * 题目数据保证对于给定的输入至少存在一个有效答案。
 * 
 * 
 */
#include <stdlib.h>
#include "../include/uthash.h"

// @lc code=start

typedef struct {
        int key;
        UT_hash_handle hh;
} hash_set;

static void insert(hash_set **set, int ikey)
{
        hash_set *tmp;
        HASH_FIND_INT(*set, &ikey, tmp);
        if (tmp == NULL) {
                tmp = malloc(sizeof(hash_set));
                tmp->key = ikey;
                HASH_ADD_INT(*set, key, tmp);
        }
}

static void free_hash_set(hash_set **set)
{
        hash_set *node, *tmp;
        HASH_ITER(hh, *set, node, tmp) {
                HASH_DEL(*set, node);
                free(node);
        }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 设 Alice 的糖果总数为 sumA，Bob 的糖果总数为 sumB，答案为 {x, y}
 * 则有 sumA - x + y = sumB - y + x，即 x = y + (sumA - sumB)/2
 *
 * 因此对于 bob_sizes 中的某一个 y'，如果能在 alice_sizes 中找到 x'
 * 使得 x' = y' + (sumA - sumB) / 2，则 {x', y'} 为一组可行解
 *
 * 为了方便在数组内找到一个数字，使用哈希表先将数字保存起来
 *
 */
int * fairCandySwap(int *alice_sizes, int alice_sizes_size,
                   int *bob_sizes, int bob_sizes_size, 
                   int *return_size){
        hash_set *set = NULL;
        int sumA = 0, sumB = 0;
        for (int i = 0; i < alice_sizes_size; i++) {
                sumA += alice_sizes[i];
                insert(&set, alice_sizes[i]);
        }

        for (int i = 0; i < bob_sizes_size; i++)
                sumB += bob_sizes[i];

        int delta = (sumA - sumB) / 2;

        int *ans = malloc(sizeof(int) * 2);
        for (int i = 0; i < bob_sizes_size; i++) {
                int x = bob_sizes[i] + delta;
                hash_set *tmp;
                HASH_FIND_INT(set, &x, tmp);
                if (tmp != NULL) {
                        ans[0] = x;
                        ans[1] = bob_sizes[i];
                        *return_size = 2;
                        break;
                }
        }

        free_hash_set(&set);

        return ans;
}
// @lc code=end


