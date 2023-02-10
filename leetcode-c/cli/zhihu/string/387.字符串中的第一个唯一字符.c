/*
 * @lc app=leetcode.cn id=387 lang=c
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode.cn/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (55.74%)
 * Likes:    638
 * Dislikes: 0
 * Total Accepted:    362.5K
 * Total Submissions: 649.8K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。
 * 如果不存在，则返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: s = "leetcode"
 * 输出: 0
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "loveleetcode"
 * 输出: 2
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "aabb"
 * 输出: -1
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 只包含小写字母
 * 
 * 
 */

// @lc code=start


/*
 * 使用一个长度为 26 的计数数组统计每个字母
 * 的出现次数。
 *
 * 重新遍历一遍字符串，找到第一个出现次数为
 * 1 的字母的索引
 *
 * T(n): O(n)
 * S(n): O(1)
 */
int firstUniqChar(char *s)
{
        int cnt[26] = {0};

        for (int i = 0; s[i] != '\0'; i++)
                cnt[s[i] - 'a']++;

        for (int i = 0; s[i] != '\0'; i++)
                if (cnt[s[i] - 'a'] == 1)
                        return i;

        return -1;
}
// @lc code=end


