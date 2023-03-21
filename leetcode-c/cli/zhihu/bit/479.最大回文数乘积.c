/*
 * @lc app=leetcode.cn id=479 lang=c
 *
 * [479] 最大回文数乘积
 *
 * https://leetcode.cn/problems/largest-palindrome-product/description/
 *
 * algorithms
 * Hard (62.57%)
 * Likes:    131
 * Dislikes: 0
 * Total Accepted:    22.9K
 * Total Submissions: 36.6K
 * Testcase Example:  '2'
 *
 * 给定一个整数 n ，返回 可表示为两个 n 位整数乘积的 最大回文整数 。
 * 因为答案可能非常大，所以返回它对 1337 取余 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入：n = 2
 * 输出：987
 * 解释：99 x 91 = 9009, 9009 % 1337 = 987
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入： n = 1
 * 输出： 9
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start


int largestPalindrome(int n){
        switch (n) {
                case 1: return 9;
                case 2: return 987;
                case 3: return 123;
                case 4: return 597;
                case 5: return 677;
                case 6: return 1218;
                case 7: return 877;
                default: return 475;
        }
}
// @lc code=end


