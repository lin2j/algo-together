/*
 * @lc app=leetcode.cn id=1356 lang=c
 *
 * [1356] 根据数字二进制下 1 的数目排序
 *
 * https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits/description/
 *
 * algorithms
 * Easy (73.28%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    58.3K
 * Total Submissions: 79.5K
 * Testcase Example:  '[0,1,2,3,4,5,6,7,8]'
 *
 * 给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。
 * 
 * 如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。
 * 
 * 请你返回排序后的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [0,1,2,3,4,5,6,7,8]
 * 输出：[0,1,2,4,8,3,5,6,7]
 * 解释：[0] 是唯一一个有 0 个 1 的数。
 * [1,2,4,8] 都有 1 个 1 。
 * [3,5,6] 有 2 个 1 。
 * [7] 有 3 个 1 。
 * 按照 1 的个数排序得到的结果数组为 [0,1,2,4,8,3,5,6,7]
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1024,512,256,128,64,32,16,8,4,2,1]
 * 输出：[1,2,4,8,16,32,64,128,256,512,1024]
 * 解释：数组中所有整数二进制下都只有 1 个 1 ，所以你需要按照数值大小将它们排序。
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [10000,10000]
 * 输出：[10000,10000]
 * 
 * 
 * 示例 4：
 * 
 * 输入：arr = [2,3,5,7,11,13,17,19]
 * 输出：[2,3,5,17,7,11,13,19]
 * 
 * 
 * 示例 5：
 * 
 * 输入：arr = [10,100,1000,10000]
 * 输出：[10,100,10000,1000]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 500
 * 0 <= arr[i] <= 10^4
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start

typedef struct {
        int num;
        char count;
} pair;

int cmp(const void *a, const void *b)
{
        pair *aa = (pair *)a;
        pair *bb = (pair *)b;

        if (aa->count != bb->count)
                return aa->count - bb->count;
        else 
                return aa->num - bb->num;
}

static char count_of_one(int n)
{
        int c = 0;
        while(n > 0) {
                c++;
                n = n & (n - 1);
        }

        return (char)c;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 定义结构体 pair 用于存储数字 num，以及对应的二进制1个数 count
 *
 * 1. 创建 pair 数组 counts，遍历 arr，将每个数字及对应的
 *    二进制1个数放入 counts 数组
 * 2. 将 counts 数组排序
 *   2.1 如果数组的 count 不相等，则根据 count 比较
 *   2.2 如果数组的 count 相等，则比较 num 本身
 * 3. 创建答案数组 result，将 counts 数组中的 num 本身按照顺序放入 result
 *
 * Tc: O(nlogn)
 * Sc: O(n)
 *
 */
int * sortByBits(int *arr, int arr_size, int *return_size)
{

        pair *counts = malloc(sizeof(pair) * arr_size);
        int idx = 0;
        for (int i = 0; i < arr_size; i++) {
                int c = count_of_one(arr[i]);
                pair p = {.num = arr[i], .count = c};
                counts[idx++] = p;
        }

        qsort(counts, arr_size, sizeof(pair), cmp);


        int *result = malloc(sizeof(int) * arr_size);
        *return_size = arr_size;

        for(int i = 0; i < arr_size; i++)
                result[i] = counts[i].num;

        free(counts);

        return result;
}
// @lc code=end


