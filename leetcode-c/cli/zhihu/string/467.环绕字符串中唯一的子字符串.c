/*
 * @lc app=leetcode.cn id=467 lang=c
 *
 * [467] 环绕字符串中唯一的子字符串
 *
 * https://leetcode.cn/problems/unique-substrings-in-wraparound-string/description/
 *
 * algorithms
 * Medium (51.80%)
 * Likes:    369
 * Dislikes: 0
 * Total Accepted:    35.8K
 * Total Submissions: 69.1K
 * Testcase Example:  '"a"'
 *
 * 定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串，
 * 所以 base 看起来是这样的：
 * 
 * 
 * "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
 * 
 * 
 * 给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "a"
 * 输出：1
 * 解释：字符串 s 的子字符串 "a" 在 base 中出现。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cac"
 * 输出：2
 * 解释：字符串 s 有两个子字符串 ("a", "c") 在 base 中出现。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "zab"
 * 输出：6
 * 解释：字符串 s 有六个子字符串 ("z", "a", "b", "za", "ab", and "zab") 在 base 中出现。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 由小写英文字母组成
 * 
 * 
 */
#include <stdbool.h>

// @lc code=start

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/*
 * 对于某个字符 c 结尾的字符串，它的长度等于以该字符结尾的子串数量。
 * 而且，对于两个以同一字符结尾的字符串，长的子串一定包含了短的子串。
 *
 * 因此可以统计题目规定的字符集（此处是小写字母）中，以每个字符结尾的
 * 最大长度，最终将这些最大长度相加即为答案
 *
 * 创建数组 dp，dp[c] 表示以 c 结尾的字符串的最大长度，在迭代过程中
 * 保存以 c 结尾的字符串的最大长度
 *
 * 判断两个字符相邻的方法是 (c1 - c2 + 26) % 26 == 1，即字符之差为 1 或 -25
 */
int findSubstringInWraproundString(char *p)
{
        int dp[26] = {0};

        int k;
        for (int i = 0; p[i] != '\0'; i++) {
                if (i > 0 && (p[i] - p[i - 1] + 26) % 26 == 1) {
                        k++;
                } else {
                        k = 1;
                }
                dp[p[i] - 'a'] = MAX(dp[p[i]- 'a'], k);
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++)
                ans += dp[i];

        return ans;
}
// @lc code=end


