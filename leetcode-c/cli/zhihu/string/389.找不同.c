/*
 * @lc app=leetcode.cn id=389 lang=c
 *
 * [389] 找不同
 *
 * https://leetcode.cn/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (67.44%)
 * Likes:    368
 * Dislikes: 0
 * Total Accepted:    150.5K
 * Total Submissions: 223.2K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t ，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abcd", t = "abcde"
 * 输出："e"
 * 解释：'e' 是那个被添加的字母。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "", t = "y"
 * 输出："y"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 1000
 * t.length == s.length + 1
 * s 和 t 只包含小写字母
 * 
 * 
 */

// @lc code=start

/*
 * 使用长度为 26 的计数数组
 *
 * 先统计 s 中的字母的个数
 *
 * 遍历 t，遇到 t 中的每一个字母都将
 * 计数数组的计数减一
 *
 * 遍历计数数组，计数小于零的字母即为
 * 被添加的字母
 */
char findTheDifference(char *s, char *t)
{
        int cnt[26] = {0};

        for (int i = 0; s[i] != '\0'; i++)
                cnt[s[i] - 'a']++;

        for (int i = 0; t[i] != '\0'; i++)
                cnt[t[i] - 'a']--;

        for (int i = 0; i < 26; i++)
                if (cnt[i] < 0) return i + 'a';

        return '\0';
}
// @lc code=end


