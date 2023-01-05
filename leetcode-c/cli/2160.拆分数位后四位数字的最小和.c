/*
 * @lc app=leetcode.cn id=2160 lang=c
 *
 * [2160] 拆分数位后四位数字的最小和
 *
 * https://leetcode.cn/problems/minimum-sum-of-four-digit-number-after-splitting-digits/description/
 *
 * algorithms
 * Easy (85.13%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    11.8K
 * Total Submissions: 13.8K
 * Testcase Example:  '2932'
 *
 * 给你一个四位 正 整数 num 。请你使用 num 中的 数位 ，将 num 拆成两个新的
 * 整数 new1 和 new2 。new1 和 new2 中可以有 前导 0 ，且 num 中 所有 数位都
 * 必须使用。
 * 
 * 
 * 比方说，给你 num = 2932 ，你拥有的数位包括：两个 2 ，一个 9 和一个 3 。
 * 一些可能的 [new1, new2] 数对为 [22, 93]，[23, 92]，[223, 9] 和 [2, 329] 。
 * 
 * 
 * 请你返回可以得到的 new1 和 new2 的 最小 和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：num = 2932
 * 输出：52
 * 解释：可行的 [new1, new2] 数对为 [29, 23] ，[223, 9] 等等。
 * 最小和为数对 [29, 23] 的和：29 + 23 = 52 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：num = 4009
 * 输出：13
 * 解释：可行的 [new1, new2] 数对为 [0, 49] ，[490, 0] 等等。
 * 最小和为数对 [4, 9] 的和：4 + 9 = 13 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1000 <= num <= 9999
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start


static inline int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/**
 * 1. 将数位从小到大排序
 * 2. 当两个数字位数相同，且各自的最高位低于最低位时，和最小
 *
 * 具体证明可以看官方题解
 * 
 * T(n): O(1)
 * S(n): O(1)
 */
int minimumSum(int num)
{
        int digits[4] = {0};
        int idx = 0;
        while(num > 0) {
                digits[idx++] = num % 10;
                num /= 10;
        }

        qsort(digits, 4, sizeof(int), cmp);
        return 10 * (digits[0] + digits[1]) + digits[2] + digits[3];
}
// @lc code=end


