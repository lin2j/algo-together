/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 找出字符串中第一个匹配项的下标
 *
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Medium (42.08%)
 * Likes:    1769
 * Dislikes: 0
 * Total Accepted:    807.4K
 * Total Submissions: 1.9M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 
 * 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 
 * 的一部分，则返回  -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * 解释："sad" 在下标 0 和 6 处匹配。
 * 第一个匹配项的下标是 0 ，所以返回 0 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack 和 needle 仅由小写英文字符组成
 * 
 * 
 */
#include <stdbool.h>

// @lc code=start

/*
 * 暴力法
 *
 * T(n): O(mn), m 为 haystack 的长度，n 为 needle 的长度
 * S(n): O(1)
 */
int strStr(char *haystack, char *needle)
{
        int i = 0;
        for (; haystack[i] != '\0'; i++) {
                bool checked = true;
                for (int k = i, j = 0; needle[j] != '\0'; k++, j++) {
                        if (haystack[k] != needle[j]) {
                                checked = false;
                                break;
                        }
                }
                if (checked) {
                        return i;
                }
        }
        return -1;
}
// @lc code=end


