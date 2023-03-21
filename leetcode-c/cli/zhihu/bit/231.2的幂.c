/*
 * @lc app=leetcode.cn id=231 lang=c
 *
 * [231] 2 的幂
 *
 * https://leetcode.cn/problems/power-of-two/description/
 *
 * algorithms
 * Easy (50.28%)
 * Likes:    589
 * Dislikes: 0
 * Total Accepted:    281.5K
 * Total Submissions: 560.4K
 * Testcase Example:  '1'
 *
 * 给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
 * 
 * 如果存在一个整数 x 使得 n == 2^x ，则认为 n 是 2 的幂次方。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 1
 * 输出：true
 * 解释：2^0 = 1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 16
 * 输出：true
 * 解释：2^4 = 16
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 3
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：n = 4
 * 输出：true
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：n = 5
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -2^31 
 * 
 * 
 * 
 * 
 * 进阶：你能够不使用循环/递归解决此问题吗？
 * 
 */
#include <stdbool.h>
#include <stdint.h>

// @lc code=start


/*
 * 2 的幂只会有一个二进制 1，将这个 1 消除后，
 * 全部位都是 0
 */
bool isPowerOfTwo(int n){
        return n > 0 && (n & (n - 1)) == 0;
}
// @lc code=end


