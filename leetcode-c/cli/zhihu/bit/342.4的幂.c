/*
 * @lc app=leetcode.cn id=342 lang=c
 *
 * [342] 4的幂
 *
 * https://leetcode.cn/problems/power-of-four/description/
 *
 * algorithms
 * Easy (52.77%)
 * Likes:    338
 * Dislikes: 0
 * Total Accepted:    126.1K
 * Total Submissions: 238.9K
 * Testcase Example:  '16'
 *
 * 给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。
 * 
 * 整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4^x
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 16
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 5
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 1
 * 输出：true
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
#include <math.h>
#include <stdbool.h>

// @lc code=start


/*
 * 先求出根号 n，那么如果是 4 的幂
 * 根号 n 会是 2 的幂
 */
bool isPowerOfFour(int n){
        if (n <= 0) return false;
        int x = (int) sqrt(n);
        // x 可能因为取整而变成 2 的幂
        // 比如 sqrt(5) 的结果是 2
        return x * x == n && (x & (x - 1)) == 0;
}
// @lc code=end


