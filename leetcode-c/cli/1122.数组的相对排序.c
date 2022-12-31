/*
 * @lc app=leetcode.cn id=1122 lang=c
 *
 * [1122] 数组的相对排序
 *
 * https://leetcode.cn/problems/relative-sort-array/description/
 *
 * algorithms
 * Easy (70.73%)
 * Likes:    247
 * Dislikes: 0
 * Total Accepted:    82.6K
 * Total Submissions: 116.8K
 * Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
 *
 * 给你两个数组，arr1 和 arr2，arr2 中的元素各不相同，arr2 中的每个元素都
 * 出现在 arr1 中。
 * 
 * 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相
 * 同。未在 arr2 中出现过的元素需要按照升序放在 arr1
 * 的末尾。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * 输出：[2,2,2,1,4,3,3,9,6,7,19]
 * 
 * 
 * 示例  2:
 * 
 * 
 * 输入：arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
 * 输出：[22,28,8,6,17,44]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * arr2 中的元素 arr2[i]  各不相同 
 * arr2 中的每个元素 arr2[i] 都出现在 arr1 中
 * 
 * 
 */
#include <stdlib.h>
// @lc code=start

#define RANGE_MIN 0
#define RANGE_MAX 1000

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 考虑到数组中的元素范围在 [0, 1000]
 * 1. 使用计数排序，先将 arr1 中元素的个数统计起来，存放在 count_arr
 * 2. 遍历 arr2，将 arr2 遇到的数字从 count_arr 找到，按照元素的个数放入 result
 * 3. arr2 遍历结束之后，在遍历一次 count_arr，将遇到的数字依次放入 result
 *
 * 优化：可以先统计 arr1 中的最大最小值，再来确定计数数组的长度
 *       不过为了编程方便，这里没有计算最大最小值
 *
 */
int * relativeSortArray(int *arr1, int arr1_size,
                        int *arr2, int arr2_size, int *return_size)
{
        *return_size = arr1_size;
        int *result = malloc(sizeof(int) * arr1_size);

        int count_arr[RANGE_MAX + 1] = {0};

        for (int i = 0; i < arr1_size; i++)
                count_arr[arr1[i]]++;

        int index = 0;
        for (int i = 0; i < arr2_size; i++) {
                int n = arr2[i];
                while(count_arr[n]-- > 0)
                        result[index++] = n;
        }

        for (int i = RANGE_MIN; i <= RANGE_MAX; i++)
                while(count_arr[i]-- > 0)
                        result[index++] = i;

        return result;
}
// @lc code=end


