/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 *
 * https://leetcode.cn/problems/reverse-integer/description/
 *
 * algorithms
 * Medium (35.50%)
 * Total Accepted:    1.3M
 * Total Submissions: 3.7M
 * Testcase Example:  '123'
 *
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 * 
 * 如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
 * 假设环境不允许存储 64 位整数（有符号或无符号）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 123
 * 输出：321
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = -123
 * 输出：-321
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：x = 120
 * 输出：21
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：x = 0
 * 输出：0
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
 */



// @lc code=start

int MAX_INT32 = 0x7fffffff;
int MIN_INT32 = 0x80000000;

/*
 * 考察边界判断, 整数溢出
 */
int reverse(int x)
{
        if (x == MIN_INT32) return 0;

        int flag = x < 0 ? -1 : 1;
        x = x * flag;

        int ans = 0, mod = 0;
        // 如果反转后整数超过 32 位的有符号整数
        // 的范围 [−2^31,  2^31 − 1] 则返回0
        while (x != 0) {
                if (MAX_INT32 / 10 < ans) {
                        return 0;
                }
                if (MAX_INT32 - mod < ans * 10) {
                        return 0;
                }
                mod = x % 10;
                ans = ans * 10 + mod;
                x /= 10;
        }

        return ans * flag;
}

// @lc code=end

