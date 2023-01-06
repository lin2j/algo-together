/*
 * @lc app=leetcode.cn id=2099 lang=c
 *
 * [2099] 找到和最大的长度为 K 的子序列
 *
 * https://leetcode.cn/problems/find-subsequence-of-length-k-with-the-largest-sum/description/
 *
 * algorithms
 * Easy (48.70%)
 * Likes:    30
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 16.8K
 * Testcase Example:  '[2,1,3,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k 。你需要找到 nums 中长度为 k 的 子序
 * 列 ，且这个子序列的 和最大 。
 * 
 * 请你返回 任意 一个长度为 k 的整数子序列。
 * 
 * 子序列 定义为从一个数组里删除一些元素后，不改变剩下元素的顺序得到的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [2,1,3,3], k = 2
 * 输出：[3,3]
 * 解释：
 * 子序列有最大和：3 + 3 = 6 。
 * 
 * 示例 2：
 * 
 * 输入：nums = [-1,-2,3,4], k = 3
 * 输出：[-1,3,4]
 * 解释：
 * 子序列有最大和：-1 + 3 + 4 = 6 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [3,4,3,3], k = 2
 * 输出：[3,4]
 * 解释：
 * 子序列有最大和：3 + 4 = 7 。
 * 另一个可行的子序列为 [4, 3] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * -10^5 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start
typedef struct {
        int num;
        int index;
} pair;


// 按元素本身排序
static inline int cmp(const void *a, const void *b)
{
        pair *pa = (pair *)a;
        pair *pb = (pair *)b;
        return pb->num - pa->num;
}

// 按索引排序
static inline int cmp2(const void *a, const void *b)
{
        pair *pa = (pair *)a;
        pair *pb = (pair *)b;
        return pa->index - pb->index;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * maxSubsequence(int *nums, int nums_size, 
                     int k, int *return_size)
{
        pair *nums_pair = malloc(sizeof(pair) * nums_size);
        for (int i = 0; i < nums_size; i++) {
                pair p = {.num = nums[i], .index = i};
                nums_pair[i] = p;
        }

        qsort(nums_pair, nums_size, sizeof(pair), cmp);
        qsort(nums_pair, k, sizeof(pair), cmp2);

        *return_size = k;
        int *result = malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++)
                result[i] = nums_pair[i].num;

        return result;
}
// @lc code=end


