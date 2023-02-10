/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode.cn/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (65.72%)
 * Likes:    706
 * Dislikes: 0
 * Total Accepted:    532.6K
 * Total Submissions: 810.4K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * s 和 t 仅包含小写字母
 * 
 * 
 * 
 * 
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */
#include <stdbool.h>

// @lc code=start


/*
 * 使用长度为 26 的计数数组
 *
 * 先统计 s 中的字母的个数
 *
 * 遍历 t，遇到 t 中的每一个字母都将
 * 计数数组的计数减一
 *
 * 遍历计数数组，若计数数组全都为 0
 * 则表示两个字符串为字母异位词
 */
bool isAnagram(char *s, char *t)
{
        int cnt[26] = {0};

        for (int i = 0; s[i] != '\0'; i++)
                cnt[s[i] - 'a']++;

        for (int i = 0; t[i] != '\0'; i++)
                cnt[t[i] - 'a']--;

        for (int i = 0; i < 26; i++)
                if (cnt[i] != 0) return false;

        return true;
}
// @lc code=end


