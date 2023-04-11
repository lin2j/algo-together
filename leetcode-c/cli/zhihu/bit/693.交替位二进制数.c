/*
 * @lc app=leetcode.cn id=693 lang=c
 *
 * [693] 交替位二进制数
 *
 * https://leetcode.cn/problems/binary-number-with-alternating-bits/description/
 *
 * algorithms
 * Easy (65.15%)
 * Likes:    228
 * Dislikes: 0
 * Total Accepted:    76.4K
 * Total Submissions: 117.2K
 * Testcase Example:  '5'
 *
 * 给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 5
 * 输出：true
 * 解释：5 的二进制表示是：101
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 7
 * 输出：false
 * 解释：7 的二进制表示是：111.
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 11
 * 输出：false
 * 解释：11 的二进制表示是：1011.
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */
#include <stdbool.h>

// @lc code=start

/*
 * 将 n 右移一位得到 m，将 m n 进行异或得到 a
 * 如果 n 是交替位二进制数，那么 a 将是形如 0000...1111 
 * 的数字，那么 a+1 为  0000...10000
 *
 * 则 a & (a + 1) 的结果为 0
 */
bool hasAlternatingBits(int n)
{
        long a = n ^ (n >> 1);
        return (a & (a + 1)) == 0;
}

// @lc code=end


