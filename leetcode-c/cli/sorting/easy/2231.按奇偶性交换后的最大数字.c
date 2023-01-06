/*
 * @lc app=leetcode.cn id=2231 lang=c
 *
 * [2231] 按奇偶性交换后的最大数字
 *
 * https://leetcode.cn/problems/largest-number-after-digit-swaps-by-parity/description/
 *
 * algorithms
 * Easy (64.12%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    10.7K
 * Total Submissions: 16.6K
 * Testcase Example:  '1234'
 *
 * 给你一个正整数 num 。你可以交换 num 中 奇偶性 相同的任意两位
 * 数字（即，都是奇数或者偶数）。
 * 
 * 返回交换 任意 次之后 num 的 最大 可能值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：num = 1234
 * 输出：3412
 * 解释：交换数字 3 和数字 1 ，结果得到 3214 。
 * 交换数字 2 和数字 4 ，结果得到 3412 。
 * 注意，可能存在其他交换序列，但是可以证明 3412 是最大可能值。
 * 注意，不能交换数字 4 和数字 1 ，因为它们奇偶性不同。
 * 
 * 
 * 示例 2：
 * 
 * 输入：num = 65875
 * 输出：87655
 * 解释：交换数字 8 和数字 6 ，结果得到 85675 。
 * 交换数字 5 和数字 7 ，结果得到 87655 。
 * 注意，可能存在其他交换序列，但是可以证明 87655 是最大可能值。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num <= 10^9
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start

#define IS_ODD(a) ((a) & 1) == 1

static inline int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

int largestInteger(int num)
{
        int arr[10]  = {0};
        int even[10] = {0};
        int odd[10]  = {0};
        int arr_size = 0, even_idx = 0, odd_idx = 0;
        while(num > 0) {
                int c = num % 10;
                num /= 10;

                arr[arr_size++] = c;
                if ((c & 1) == 1)
                        odd[odd_idx++] = c;
                else
                        even[even_idx++] = c;
        }

        qsort(even, even_idx, sizeof(int), cmp);
        qsort(odd, odd_idx, sizeof(int), cmp);

        int ans = 0;
        for (int k = arr_size - 1; k >= 0; k--) {
                int d = IS_ODD(arr[k]) ?
                        odd[--odd_idx] : even[--even_idx];
                ans = 10 * ans + d;
        }

        return ans;
}
// @lc code=end


