/*
 * @lc app=leetcode.cn id=326 lang=c
 *
 * [326] 3 的幂
 *
 * https://leetcode.cn/problems/power-of-three/description/
 *
 * algorithms
 * Easy (50.93%)
 * Likes:    291
 * Dislikes: 0
 * Total Accepted:    200.3K
 * Total Submissions: 393.5K
 * Testcase Example:  '27'
 *
 * 给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。
 * 
 * 整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3^x
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 27
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 0
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 9
 * 输出：true
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：n = 45
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -2^31 <= n <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：你能不使用循环或者递归来完成本题吗？
 * 
 */
#include <stdbool.h>

// @lc code=start


/*
 * 判断是否为最大 3 的幂的约数
 */
bool isPowerOfThree(int n)
{
        return n > 0 && 1162261467 % n == 0;

}
// @lc code=end


