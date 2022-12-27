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

// @lc code=start

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 1. 先将 nums1 nums2 按递增排序
 * 2. 从 nums1 nums2 的头部开始遍历
 *   2.1 如果两个元素相等，则放入到 intersection 数组中
 *   2.2 如果两个元素不相等，则较小者继续往前遍历
 * 3. 直到遍历完某一个数组，整个过程结束
 */
int* intersect(int *nums1, int nums1_size,
               int *nums2, int nums2_size, 
               int* return_size){
        qsort(nums1, nums1_size, sizeof(int), cmp);
        qsort(nums2, nums2_size, sizeof(int), cmp);

        int i = 0, j = 0;
        *return_size = 0;
        int *intersection = malloc(sizeof(int) * (nums1_size + nums2_size));
        while(i < nums1_size && j < nums2_size) {
                int n1 = nums1[i], n2 = nums2[j];
                if (n1 == n2) {
                        intersection[(*return_size)++] = n1;
                        i++, j++;
                } else if (n1 < n2) {
                        i++;
                } else {
                        j++;
                }
        }

        return intersection;
}
// @lc code=end


