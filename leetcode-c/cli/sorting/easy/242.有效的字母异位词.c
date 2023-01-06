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
 * 输入: s = "anagram", t = "nagaram" 输出: true
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
#include <string.h>
#include <stdbool.h>

// @lc code=start

/**
 * 使用一个小写字母表记录 s 中每个元素的个数，
 * 然后遍历一次 t 中的元素，遍历到的元素时，对
 * 应的位置减一
 * 如果 s 和 t 中出现的字母相同且次数相同，那么
 * 最终字母表的所有索引位置的个数一定为 0
 */
bool isAnagram(char *s, char *t) 
{
        // 使用 char 类型会无法通过测试用例
        int count_map[26] = {0};

        while(*s != '\0' && *t != '\0') {
                count_map[*s++ - 'a']++;
                count_map[*t++ - 'a']--;
        }

        if (*s != '\0' || *t != '\0')
                return false;

        for (int i = 0; i < 26; i++) {
                if (count_map[i] != 0)
                        return false;
        }

        return true;
}
// @lc code=end

