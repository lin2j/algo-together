/*
 * @lc app=leetcode.cn id=434 lang=c
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode.cn/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (38.95%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    85.7K
 * Total Submissions: 219.9K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 * 
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 * 
 * 示例:
 * 
 * 输入: "Hello, my name is John"
 * 输出: 5
 * 解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
 * 
 * 
 */

// @lc code=start

/*
 * 统计有多少个单词，可以统计单词的第一个下标的个数
 *
 * 满足是单词的第一个下标的条件为：
 * 1. 不能为空格
 * 2. 是初始下标或者该下标对应的前一个字符是空格
 *
 */
int countSegments(char * s)
{
        int segment_count = 0;

        for (int i = 0; s[i] != '\0'; i++)
                if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
                        segment_count++;

        return segment_count;
}
// @lc code=end


