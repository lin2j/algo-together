/*
 * @lc app=leetcode.cn id=476 lang=c
 *
 * [476] 数字的补数
 *
 * https://leetcode.cn/problems/number-complement/description/
 *
 * algorithms
 * Easy (69.72%)
 * Likes:    336
 * Dislikes: 0
 * Total Accepted:    80.6K
 * Total Submissions: 115.5K
 * Testcase Example:  '5'
 *
 * 对整数的二进制表示取反（0 变 1 ，1 变 0）后，再转换为十进制表示，可以得到这个整数的补数。
 * 
 * 
 * 例如，整数 5 的二进制表示是 "101" ，取反后得到 "010" ，再转回十进制表示得到补数 2 。
 * 
 * 
 * 给你一个整数 num ，输出它的补数。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 
 * 输入：num = 5
 * 输出：2
 * 解释：5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：num = 1
 * 输出：0
 * 解释：1 的二进制表示为 1（没有前导零位），其补数为 0。所以你需要输出 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num < 2^31
 * 
 * 
 * 
 * 
 * 注意：本题与 1009 https://leetcode-cn.com/problems/complement-of-base-10-integer/
 * 相同
 * 
 */

// @lc code=start

/*
 * 先找到最高位的 1，然后将最高位的 1 即低位进行翻转,
 * 设最高位为 h，mask 为低 h 为均为 1 的掩码
 * num ^ mask 即为结果
 */
int findComplement(int num)
{
        // 找到最高位的 1
        int h = 0;
        for (int i = 0; i < 31; i++)
                if ((num & (1 << i)) != 0)
                        h = i;

        // 通过掩码进行位翻转
        int mask = (h == 30 ? 0x7fffffff : (1 << (h + 1)) - 1);
        return num ^ mask;
}
// @lc code=end

 
