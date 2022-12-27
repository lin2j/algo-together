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

// @lc code=start

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 1. 先将两个数组按照递增的方式排序
 * 2. 遍历两个数组，将交集元素放在 intersection 数组之中
 *   2.1 如果两个元素相同，则判断 intersection 的最新元素是否
 *       等于该元素，不同时才将这个元素放入到 intersection
 *   2.2 如果两个元素不相同，则元素较小的数组继续往前遍历
 * 3. 当某个数组先遍历完时，整个过程结束
 */
int * intersection(int *nums1, int nums1_size,
                   int *nums2, int nums2_size, 
                   int *return_size)
{
        qsort(nums1, nums1_size, sizeof(int), cmp);
        qsort(nums2, nums2_size, sizeof(int), cmp);
        
        *return_size = 0;
        int len = nums1_size > nums2_size ? nums2_size : nums1_size;
        int *intersection = malloc(sizeof(int) * len);

        int i = 0, j = 0;
        while(i < nums1_size && j < nums2_size) {
                int n1 = nums1[i], n2 = nums2[j];
                if (n1 == n2) {
                        if (*return_size == 0 || n1 != intersection[*(return_size) - 1]) {
                                intersection[(*return_size)++] = n1;
                        }
                        i++, j++;
                } else if (n1 < n2){
                        i++;
                } else {
                        j++;
                }
        }
        return intersection;
}
// @lc code=end


