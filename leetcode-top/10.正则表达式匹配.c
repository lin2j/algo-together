/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode.cn/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (30.70%)
 * Total Accepted:    424.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * 
 * 
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 
 * 
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aa", p = "a"
 * 输出：false
 * 解释："a" 无法匹配 "aa" 整个字符串。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：s = "aa", p = "a*"
 * 输出：true
 * 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "ab", p = ".*"
 * 输出：true
 * 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 20
 * 1 <= p.length <= 20
 * s 只包含从 a-z 的小写字母。
 * p 只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 保证每次出现字符 * 时，前面都匹配到有效的字符
 * 
 * 
 */

#include <stdbool.h>


// @lc code=start

bool __match(char *s, char *p, int m, int n)
{
        if (p[n] == '\0') return s[m] == '\0';

        bool first_match = s[m] != '\0' && (s[m] == p[n] || p[n] == '.');

        if (p[n + 1] != '\0' && p[n + 1] == '*')
                // 第二个判断是处理 * 已经不匹配之后的情况
                // 所以 +2 跳过星号
                return (first_match && __match(s, p, m + 1, n)) 
                        || __match(s, p, m, n + 2);

        return first_match && __match(s, p, m + 1, n + 1);
}

bool isMatch(char *s, char *p) 
{
        return __match(s, p, 0, 0);
}

// @lc code=end

