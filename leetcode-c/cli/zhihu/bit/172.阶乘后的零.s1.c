/*
 * @lc app=leetcode.cn id=172 lang=c
 *
 * [172] 阶乘后的零
 *
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Medium (49.88%)
 * Total Accepted:    166.9K
 * Total Submissions: 334.6K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n ，返回 n! 结果中尾随零的数量。
 * 
 * 提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：0
 * 解释：3! = 6 ，不含尾随 0
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 5
 * 输出：1
 * 解释：5! = 120 ，有一个尾随 0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 0
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 10^4
 * 
 * 
 * 
 * 
 * 进阶：你可以设计并实现对数时间复杂度的算法来解决此问题吗？
 * 
 */


/*
 * 尾数为 0 的个数为 n! 中因子 10 的个数，而 10 = 2 * 5
 * 因此求出 n！中，质因子 2 和 5 的个数的最小值，即为
 * 因子 10 的个数
 *
 * 由于质因子 5 的个数不会大于 2 的个数，所以仅考虑质因子 5 的个数
 */
int trailingZeroes(int n)
{
        int c = 0;
        while (n) {
                n /= 5;
                c += n;
        }
        return c;
}

