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

#include <string.h>
#include <stdlib.h>

// @lc code=start

/*
 * 1. 将 s、t 排序
 * 2. 同时遍历 s、t，如果发现两个元素不一样，则返回 t[i]
 * 3. 如果遍历结束了依然没有发现不同元素，则 t[len_s] 为答案
 */
char findTheDifference(char *s, char *t){
        int count_map[26] = {0};
        while(*s != '\0' || *t != '\0') {
                if (*s != '\0')
                        count_map[*s++ - 'a']++;
                count_map[*t++ - 'a']--;
        }

        for (int i = 0; i < 26; i++)
                if (count_map[i] != 0)
                        return (char)(i + 'a');

        return '\0';
}
// @lc code=end


