/*
 * @lc app=leetcode.cn id=2154 lang=c
 *
 * [2154] 将找到的值乘以 2
 *
 * https://leetcode.cn/problems/keep-multiplying-found-values-by-two/description/
 *
 * algorithms
 * Easy (73.82%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 19.3K
 * Testcase Example:  '[5,3,6,1,12]\n3'
 *
 * 给你一个整数数组 nums ，另给你一个整数 original ，
 * 这是需要在 nums 中搜索的第一个数字。
 * 
 * 接下来，你需要按下述步骤操作：
 * 
 * 
 * 如果在 nums 中找到 original ，将 original 乘以 2 ，得到新
 * original（即，令 original = 2 * original）。
 * 否则，停止这一过程。
 * 只要能在数组中找到新 original ，就对新 original 继续 重复 这一过程。
 * 
 * 
 * 返回 original 的 最终 值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,3,6,1,12], original = 3
 * 输出：24
 * 解释： 
 * - 3 能在 nums 中找到。3 * 2 = 6 。
 * - 6 能在 nums 中找到。6 * 2 = 12 。
 * - 12 能在 nums 中找到。12 * 2 = 24 。
 * - 24 不能在 nums 中找到。因此，返回 24 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,7,9], original = 4
 * 输出：4
 * 解释：
 * - 4 不能在 nums 中找到。因此，返回 4 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i], original <= 1000
 * 
 * 
 */
#include <stdlib.h>
#include <stdbool.h>
#include "include/uthash.h"

// @lc code=start


typedef struct {
        int key;
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

/*
 * 可以将 nums 的元素放到哈希表中，之后每次判断
 * original 是否在哈希表中即可
 *
 * T(n): O(n)
 * S(n): O(n)
 */
int findFinalValue(int *nums, int nums_size, int original)
{
        hash_set *set = NULL, *tmp;
        for (int i = 0; i < nums_size; i++) {
                HASH_FIND_INT(set, &nums[i], tmp);
                if (tmp == NULL) {
                        tmp = malloc(sizeof(hash_set));
                        tmp->key = nums[i];
                        HASH_ADD_INT(set, key, tmp);
                }
        }

        while(true) {
                HASH_FIND_INT(set, &original, tmp);
                if (tmp != NULL) original *= 2;
                else break;
        }

        hash_set *node;
        HASH_ITER(hh, set, node, tmp) {
                HASH_DEL(set, node);
                free(node);
        }

        return original;
}
// @lc code=end


