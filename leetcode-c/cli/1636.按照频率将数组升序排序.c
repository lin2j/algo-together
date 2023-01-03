/*
 * @lc app=leetcode.cn id=1636 lang=c
 *
 * [1636] 按照频率将数组升序排序
 *
 * https://leetcode.cn/problems/sort-array-by-increasing-frequency/description/
 *
 * algorithms
 * Easy (74.84%)
 * Likes:    145
 * Dislikes: 0
 * Total Accepted:    46K
 * Total Submissions: 61.4K
 * Testcase Example:  '[1,1,2,2,2,3]'
 *
 * 给你一个整数数组 nums ，请你将数组按照每个值的频率 升序 排序。
 * 如果有多个值的频率相同，请你按照数值本身将它们 降序 排序。 
 * 
 * 请你返回排序后的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,1,2,2,2,3]
 * 输出：[3,1,1,2,2,2]
 * 解释：'3' 频率为 1，'1' 频率为 2，'2' 频率为 3 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,3,1,3,2]
 * 输出：[1,3,3,2,2]
 * 解释：'2' 和 '3' 频率都为 2 ，所以它们之间按照数值本身降序排序。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [-1,1,-6,4,5,-6,1,4,1]
 * 输出：[5,-1,4,4,-6,-6,1,1,1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * -100 <= nums[i] <= 100
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start

#define OFFSET 100

typedef struct {
        int num;
        short freq;
} pair;

static inline int cmp(const void *a, const void *b)
{
        pair *aa = (pair *)a;
        pair *bb = (pair *)b;
        if (aa->freq != bb->freq)
                return aa->freq - bb->freq;
        else
                return bb->num - aa->num;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 定义结构体 pair 用来存储一个数字以及出现的频次
 *
 * 1. 创建频次数组 frequency，遍历 nums 记录每个元素及对应的频次
 * 2. 将频次数组进行排序，规则为：先按照频次比较，如果频次相同则比较数字本身
 * 3. 创建答案数组 result，遍历频次数组将数字按照频次填充至答案数组
 *
 * Tc: O(KlogK)，K 为将数组去重之后的元素个数
 * Sc：O(logK)
 */
int * frequencySort(int *nums, int nums_size, int *return_size)
{

        int count_map[201] = {0};
        int size = 0;
        for (int i = 0; i < nums_size; i++) {
                if (count_map[nums[i] + OFFSET] == 0) size++;
                count_map[nums[i] + OFFSET]++;
        }

        int idx = 0;
        pair *frequency = malloc(sizeof(pair) * size);
        for (int i = -100; i < 101; i++) {
                if (count_map[i + OFFSET] == 0) continue;

                short freq = (short)count_map[i + OFFSET];
                pair p = {.num = i, .freq = freq};
                frequency[idx++] = p;
        }

        qsort(frequency, size, sizeof(pair), cmp);

        *return_size = nums_size;
        int *result = malloc(sizeof(int) * nums_size);
        idx = 0;
        for (int i = 0; i < size; i++) {
                int freq = frequency[i].freq;
                int num = frequency[i].num;
                while(freq-- > 0) result[idx++] = num;
        }

        return result;
}
// @lc code=end


