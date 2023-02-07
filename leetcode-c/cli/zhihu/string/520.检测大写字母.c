/*
 * @lc app=leetcode.cn id=520 lang=c
 *
 * [520] 检测大写字母
 *
 * https://leetcode.cn/problems/detect-capital/description/
 *
 * algorithms
 * Easy (57.01%)
 * Likes:    228
 * Dislikes: 0
 * Total Accepted:    83.9K
 * Total Submissions: 147.3K
 * Testcase Example:  '"USA"'
 *
 * 我们定义，在以下情况时，单词的大写用法是正确的：
 * 
 * 
 * 全部字母都是大写，比如 "USA" 。
 * 单词中所有字母都不是大写，比如 "leetcode" 。
 * 如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
 * 
 * 
 * 给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：word = "USA"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：word = "FlaG"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= word.length <= 100
 * word 由小写和大写英文字母组成
 * 
 * 
 */
#include <stdbool.h>
#include <string.h>

// @lc code=start

#define IS_UPPER(c) ((c) >= 'A' && (c) <= 'Z')
#define IS_LOWER(c) ((c) >= 'a' && (c) <= 'z')

/*
 * 如果单词长度为 1，则必定合法
 *
 * 如果单词长度超过 2，则
 * 1. 如果前两个字母均为大写，则后面全部都需要为大写
 * 2. 如果首字母大写，第二个字母小写，则后面全部都为小写
 * 3. 如果前两个字母均为小写，则后面全部都需要为小写
 *
 * 如果第一个字母为小写，则需额外判断第二个字母是否为小写
 */
bool detectCapitalUse(char *word)
{
        int len_word = strlen(word);
        
        if (len_word == 1)
                return true;

        if (IS_LOWER(word[0]) && IS_UPPER(word[1]))
                return false;

        bool all_upper = IS_UPPER(word[0]) && IS_UPPER(word[1]);
        bool all_lower = IS_LOWER(word[0]) && IS_LOWER(word[1]);
        all_lower |= IS_UPPER(word[0]) && IS_LOWER(word[1]);

        if (all_lower) {
                for (word += 2; *word != '\0'; word++)
                        if (IS_UPPER(*word)) return false;
        } else if(all_upper) {
                for (word += 2; *word != '\0'; word++)
                        if (IS_LOWER(*word)) return false;
        }

        return true;
} 
// @lc code=end


