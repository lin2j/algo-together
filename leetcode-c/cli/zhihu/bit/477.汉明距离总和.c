/*
 * @lc app=leetcode.cn id=477 lang=c
 *
 * [477] 汉明距离总和
 *
 * https://leetcode.cn/problems/total-hamming-distance/description/
 *
 * algorithms
 * Medium (60.63%)
 * Likes:    284
 * Dislikes: 0
 * Total Accepted:    45.5K
 * Total Submissions: 75.1K
 * Testcase Example:  '[4,14,2]'
 *
 * 两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
 * 
 * 给你一个整数数组 nums，请你计算并返回 nums 中任意两个数之间 汉明距离的总和 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,14,2]
 * 输出：6
 * 解释：在二进制表示中，4 表示为 0100 ，14 表示为 1110 ，2表示为 0010 。（这样表示是为了体现后四位之间关系）
 * 所以答案为：
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2
 * + 2 + 2 = 6
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,14,4]
 * 输出：4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^9
 * 给定输入的对应答案符合 32-bit 整数范围
 * 
 * 
 */

// @lc code=start

/*
 * 若某个元素 val 的第 i 位为 1，则只需要统计 nums
 * 中有多少个元素的第 i 位为 0 
 *
 * 若长度为 n 的数组所有元素的二进制第 i 位共有 c 个 1，n - c 个 0 ，
 * 则这些元素在第 i 为的汉明距离之和为 c * (n - c)
 *
 * T(n): O(n * L)，n 是数组长度，L 是 30
 * S(n): O(1)
 */
int totalHammingDistance(int* nums, int nums_size)
{
        int ans = 0;
        // 10^9 < 2^30，所以循环到 30 位即可
        for (int i = 0; i < 30; i++) {
                int c = 0;
                for (int j = 0; j < nums_size; j++)
                        c += (nums[j] >> i) & 1;
                ans += c * (nums_size - c);
        }
        return ans;
}
// @lc code=end


