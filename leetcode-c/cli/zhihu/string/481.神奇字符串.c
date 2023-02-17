/*
 * @lc app=leetcode.cn id=481 lang=c
 *
 * [481] 神奇字符串
 *
 * https://leetcode.cn/problems/magical-string/description/
 *
 * algorithms
 * Medium (64.10%)
 * Likes:    178
 * Dislikes: 0
 * Total Accepted:    34.6K
 * Total Submissions: 54K
 * Testcase Example:  '6'
 *
 * 神奇字符串 s 仅由 '1' 和 '2' 组成，并需要遵守下面的规则：
 * 
 * 
 * 神奇字符串 s 的神奇之处在于，串联字符串中 '1' 和 '2' 的连续出现次数可以生成该字符串。
 * 
 * 
 * s 的前几个元素是 s = "1221121221221121122……" 。如果将 s 中连续的若干 1 和 2 进行分组，可以得到 "1 22 11
 * 2 1 22 1 22 11 2 11 22 ......" 。每组中 1 或者 2 的出现次数分别是 "1 2 2 1 1 2 1 2 2 1 2 2
 * ......" 。上面的出现次数正是 s 自身。
 * 
 * 给你一个整数 n ，返回在神奇字符串 s 的前 n 个数字中 1 的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 6
 * 输出：3
 * 解释：神奇字符串 s 的前 6 个元素是 “122112”，它包含三个 1，因此返回 3 。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^5
 * 
 * 
 */

// @lc code=start

/*
 * 构造神奇字符串，并在构造的过程中统计 1 的个数
 *
 * 当 n 小于 4 时，122 中有 1 个 1
 * 1. 从 122 开始，构造后面的字符
 * 2. 设置 i 指向下一组的大小，j 需要构建的组的位置，
 *    且用 j 之前的数字来决定下一组数字是 1 还是 2
 *    若 s[j - 1] = 1，则需要构建一组2
 * 3. 则初始 i = 2，j = 3，以此为例，则下一组的大小是 2，
 *    需要构建的数字是 s[3 - 1] = 3 - 2 = 1
 *
 */
int magicalString(int n)
{
        if (n < 4)
                return 1;

        int ans = 1;
        char s[n + 1];
        s[0] = '1'; 
        s[1] = '2'; 
        s[2] = '2';
        int i = 2, j = 3;

        while (j < n) {
                int size = s[i] - '0';
                // 若 s[j - 1] = 1，则需要构建一组2
                int num = 3 - (s[j - 1] - '0');
                while (size > 0 && j < n) {
                        s[j] = num + '0';
                        if (num == 1)
                                ans++;
                        j++;
                        size--;
                }
                i++;
        }

        return ans;
}

// @lc code=end


