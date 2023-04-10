/*
 * @lc app=leetcode.cn id=461 lang=c
 *
 * [461] 汉明距离
 *
 * https://leetcode.cn/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (81.88%)
 * Likes:    694
 * Dislikes: 0
 * Total Accepted:    273.1K
 * Total Submissions: 333.5K
 * Testcase Example:  '1\n4'
 *
 * 两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。
 * 
 * 给你两个整数 x 和 y，计算并返回它们之间的汉明距离。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 1, y = 4
 * 输出：2
 * 解释：
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * 上面的箭头指出了对应二进制位不同的位置。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = 3, y = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 
 * 
 */

// @lc code=start

/*
 * 两个数字异或之后，计算1的个数
 */
int hammingDistance(int x, int y)
{
        int n = x ^ y;
        int c = 0;
        while (n != 0) {
                c++;
                n = (n - 1) & n;
        }
        return c;
}
// @lc code=end


