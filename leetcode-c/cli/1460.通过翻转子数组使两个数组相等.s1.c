/*
 * @lc app=leetcode.cn id=1460 lang=c
 *
 * [1460] 通过翻转子数组使两个数组相等
 *
 * https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-subarrays/description/
 *
 * algorithms
 * Easy (77.30%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    52.1K
 * Total Submissions: 67.4K
 * Testcase Example:  '[1,2,3,4]\n[2,4,1,3]'
 *
 * 给你两个长度相同的整数数组 target 和 arr 。每一步中，你可以选择 arr 的任意
 * 非空子数组并将它翻转。你可以执行此过程任意次。
 * 
 * 如果你能让 arr 变得与 target 相同，返回 True；否则，返回 False 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：target = [1,2,3,4], arr = [2,4,1,3]
 * 输出：true
 * 解释：你可以按照如下步骤使 arr 变成 target：
 * 1- 翻转子数组 [2,4,1] ，arr 变成 [1,4,2,3]
 * 2- 翻转子数组 [4,2] ，arr 变成 [1,2,4,3]
 * 3- 翻转子数组 [4,3] ，arr 变成 [1,2,3,4]
 * 上述方法并不是唯一的，还存在多种将 arr 变成 target 的方法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：target = [7], arr = [7]
 * 输出：true
 * 解释：arr 不需要做任何翻转已经与 target 相等。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：target = [3,7,9], arr = [3,7,11]
 * 输出：false
 * 解释：arr 没有数字 9 ，所以无论如何也无法变成 target 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * target.length == arr.length
 * 1 <= target.length <= 1000
 * 1 <= target[i] <= 1000
 * 1 <= arr[i] <= 1000
 * 
 * 
 */
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// @lc code=start

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/*
 * 因为可以翻转无数次，因此只要两个数组的相同即可。
 *
 * 1. 可以使用哈希表统计 targe 元素的及各自的次数
 * 2. 遍历 arr，设当前元素为 a，检查是否在哈希表中，
 *   2.1 如果在哈希表中存在，则 a 的次数减一，如果减完
 *       次数为 0，则将哈希表中的 a 删除
 *   2.2 如果哈希表中不存在 a，则可以直接返回 false
 *
 * 最终如果哈希表的元素个数为 0，则代表两个数组
 * 的元素及次数相同，即两个数组相同
 */
bool canBeEqual(int *target, int target_size,
                int *arr, int arr_size)
{
        int count[1001] = {0};
        for (int i = 0; i < target_size; i++)
                count[target[i]]++;

        for (int i = 0; i < arr_size; i++) {
                if (count[arr[i]] == 0) return false;
                count[arr[i]]--;
        }

        return true;
}
// @lc code=end


