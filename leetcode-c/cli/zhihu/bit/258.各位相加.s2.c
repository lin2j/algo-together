/*
 * @lc app=leetcode.cn id=258 lang=c
 *
 * [258] 各位相加
 *
 * https://leetcode-cn.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (71.07%)
 * Total Accepted:    161K
 * Total Submissions: 226.5K
 * Testcase Example:  '38'
 *
 * 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: num = 38
 * 输出: 2 
 * 解释: 各位相加的过程为：
 * 38 --> 3 + 8 --> 11
 * 11 --> 1 + 1 --> 2
 * 由于 2 是一位数，所以返回 2。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: num = 0
 * 输出: 0
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= num <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：你可以不使用循环或者递归，在 O(1) 时间复杂度内解决这个问题吗？
 * 
 */


/*
 *  https://leetcode.cn/problems/add-digits/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-5-7/
 *
 */
int addDigits(int num)
{
        if (num < 10) return num;

        int m = num % 9;
        return m == 0 ? 9 : m;
}

