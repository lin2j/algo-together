/*
 * @lc app=leetcode.cn id=383 lang=c
 *
 * [383] 赎金信
 *
 * https://leetcode.cn/problems/ransom-note/description/
 *
 * algorithms
 * Easy (60.27%)
 * Likes:    633
 * Dislikes: 0
 * Total Accepted:    290.3K
 * Total Submissions: 481.5K
 * Testcase Example:  '"a"\n"b"'
 *
 * 给你两个字符串：ransomNote 和 magazine ，
 * 判断 ransomNote 能不能由 magazine 里面的字符构成。
 * 
 * 如果可以，返回 true ；否则返回 false 。
 * 
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：ransomNote = "a", magazine = "b"
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：ransomNote = "aa", magazine = "aab"
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote 和 magazine 由小写英文字母组成
 * 
 * 
 */
#include <stdbool.h>

// @lc code=start

/*
 * 使用长度为 26 的计数数组
 *
 * 先统计 ransomNote 中的字母的个数
 *
 * 遍历 magazine，遇到 magazine 中的每一个字母都将
 * 计数数组的计数减一
 *
 * 遍历计数数组，若存在计数小于 0 的情况，则返回 false
 *
 */
bool canConstruct(char *ransom_note, char *magazine)
{
        int cnt[26] = {0};

        for (int i = 0; magazine[i] != '\0'; i++)
                cnt[magazine[i] - 'a']++;

        for (int i = 0; ransom_note[i] != '\0'; i++)
                cnt[ransom_note[i] - 'a']--;

        for (int i = 0; i < 26; i++)
                if (cnt[i] < 0) return false;

        return true;
}
// @lc code=end


