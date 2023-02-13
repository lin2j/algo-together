/*
 * @lc app=leetcode.cn id=696 lang=c
 *
 * [696] 计数二进制子串
 *
 * https://leetcode.cn/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (63.89%)
 * Likes:    498
 * Dislikes: 0
 * Total Accepted:    67.3K
 * Total Submissions: 105.3K
 * Testcase Example:  '"00110011"'
 *
 * 给定一个字符串 s，统计并返回具有相同数量 0 和 1 的非空（连续）子字符串的
 * 数量，并且这些子字符串中的所有 0 和所有 1 都是成组连续的。
 * 
 * 重复出现（不同位置）的子串也要统计它们出现的次数。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "00110011"
 * 输出：6
 * 解释：6 个子串满足具有相同数量的连续 1 和 0 ："0011"、"01"、"1100"、"10"、"0011" 和 "01" 。
 * 注意，一些重复出现的子串（不同位置）要统计它们出现的次数。
 * 另外，"00110011" 不是有效的子串，因为所有的 0（还有 1 ）没有组合在一起。
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "10101"
 * 输出：4
 * 解释：有 4 个子串："10"、"01"、"10"、"01" ，具有相同数量的连续 1 和 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] 为 '0' 或 '1'
 * 
 * 
 */
#include <string.h>
#include <stdlib.h>

// @lc code=start

#define MIN(a, b) ((a) > (b) ? (b) : (a))

/*
 * 遍历数组，统计连续出现的字符的次数，
 * 比如对于字符串 ”00111000011111“ 统计的结果是 cnt = {2, 3, 4, 5}
 *
 * 以 2、3 为例，表示有 2 个连续 0，3 个连续 1，即 00111
 * 而 00111 分别有 0011、01 两个字符串符合题意，即 Min(2, 3) = 2
 *
 * 因此可以遍历 cnt 数组，对每个相邻的数字进行比较，去较小者，最终
 * 将所有的比较结果求和即为答案
 *
 */
int countBinarySubstrings(char *s)
{
        int len_s = strlen(s);
        int cnt[len_s];
        memset(cnt, 0, sizeof(int) * len_s);

        int k = 0;
        for (int i = 0; s[i] != '\0'; ) {
                int c = 0;
                char t = s[i];
                while(s[i] != '\0' && t == s[i]) {
                        c++;
                        i++;
                }
                cnt[k++] = c;
        }

        int ans = 0;
        for (int i = 1; i < k; i++)
                ans += MIN(cnt[i], cnt[i - 1]);

        return ans;
}
// @lc code=end























































