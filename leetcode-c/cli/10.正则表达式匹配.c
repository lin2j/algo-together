/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode.cn/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (31.66%)
 * Likes:    3210
 * Dislikes: 0
 * Total Accepted:    315.5K
 * Total Submissions: 996.4K
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
 * 1 <= p.length <= 30
 * s 只包含从 a-z 的小写字母。
 * p 只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 保证每次出现字符 * 时，前面都匹配到有效的字符
 * 
 * 
 */
#include <stdbool.h>

// @lc code=start

bool __is_match(char *s, char *p, int n, int m)
{
        if(p[m] == '\0') return s[n] == '\0';
        bool first_match = (s[n] != '\0') && (s[n] == p[m] || p[m] == '.');
        if (p[m + 1] != '\0' && p[m + 1] == '*') {
                return (first_match && __is_match(s, p, n + 1, m)) ||
                        __is_match(s, p, n, m + 2);
        } else {
                return first_match && __is_match(s, p, n + 1, m + 1);
        }
}


bool isMatch(char *s, char *p){

        return __is_match(s, p, 0, 0);
}
// @lc code=end

