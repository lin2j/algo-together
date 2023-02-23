/*
 * @lc app=leetcode.cn id=306 lang=c
 *
 * [306] 累加数
 *
 * https://leetcode.cn/problems/additive-number/description/
 *
 * algorithms
 * Medium (38.00%)
 * Likes:    393
 * Dislikes: 0
 * Total Accepted:    47K
 * Total Submissions: 123.7K
 * Testcase Example:  '"112358"'
 *
 * 累加数 是一个字符串，组成它的数字可以形成累加序列。
 * 
 * 一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，序列中的每个后续数字必须是它之前两个数字之和。
 * 
 * 给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数 。如果是，返回 true ；否则，返回 false 。
 * 
 * 说明：累加序列里的数，除数字 0 之外，不会 以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入："112358"
 * 输出：true 
 * 解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入："199100199"
 * 输出：true 
 * 解释：累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num.length <= 35
 * num 仅由数字（0 - 9）组成
 * 
 * 
 * 
 * 
 * 进阶：你计划如何处理由过大的整数输入导致的溢出?
 * 
 */
#include <stdbool.h>

// @lc code=start


bool isAdditiveNumber(char *num)
{

}
// @lc code=end


