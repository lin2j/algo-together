/*
 * @lc app=leetcode.cn id=1346 lang=c
 *
 * [1346] 检查整数及其两倍数是否存在
 *
 * https://leetcode.cn/problems/check-if-n-and-its-double-exist/description/
 *
 * algorithms
 * Easy (42.45%)
 * Likes:    81
 * Dislikes: 0
 * Total Accepted:    31.7K
 * Total Submissions: 74.7K
 * Testcase Example:  '[10,2,5,3]'
 *
 * 给你一个整数数组 arr，请你检查是否存在两个整数 N 和 M，
 * 满足 N 是 M 的两倍（即，N = 2 * M）。
 * 
 * 更正式地，检查是否存在两个下标 i 和 j 满足：
 * 
 * 
 * i != j
 * 0 <= i, j < arr.length
 * arr[i] == 2 * arr[j]
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [10,2,5,3]
 * 输出：true
 * 解释：N = 10 是 M = 5 的两倍，即 10 = 2 * 5 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [7,1,14,11]
 * 输出：true
 * 解释：N = 14 是 M = 7 的两倍，即 14 = 2 * 7 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [3,1,7,11]
 * 输出：false
 * 解释：在该情况下不存在 N 和 M 满足 N = 2 * M 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= arr.length <= 500
 * -10^3 <= arr[i] <= 10^3
 * 
 * 
 */
#include <stdbool.h>
#include <stdlib.h>

// @lc code=start

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

static int bin_search(int *arr, int l, int r, int target)
{
        if (l > r) return -1;
        while(l <= r) {
                int mid = (l + r) / 2;
                if (arr[mid] == target)
                        return mid;
                else if (arr[mid] < target)
                        l = mid + 1;
                else
                        r = mid - 1;
        }
        return -1;
}

/**
 * 1. 将 arr 排序
 * 2. 遍历 arr，设当前索引为 i，元素为 a，使用二分查找，在数组内查找 2a
 *  2.1 如果 a 小于 0，则从 [0, i) 查找
 *  2.2 如果 a 大于 0，则从 (i, arr_size) 查找
 * 3. arr 遍历完依旧没有找到符合条件的 N 和 M，返回 false
 *
 * Tc: O(nlogn)
 * Sc: O(logn)
 */
bool checkIfExist(int *arr, int arr_size){
        qsort(arr, arr_size, sizeof(int), cmp);

        int n = arr_size - 1;
        for (int i = 0; i < arr_size; i++) {
                int a = arr[i];
                int pos = -1;
                if (a < 0) {
                        pos = bin_search(arr, 0, i - 1, 2 * a);
                } else {
                        pos = bin_search(arr, i + 1, n, 2 * a);
                }
                if (pos != -1) {
                        return true;
                }
        }
        return false;
}

// @lc code=end


