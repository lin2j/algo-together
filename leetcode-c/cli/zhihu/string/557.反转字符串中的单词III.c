/*
 * @lc app=leetcode.cn id=557 lang=c
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (74.16%)
 * Likes:    516
 * Dislikes: 0
 * Total Accepted:    287.7K
 * Total Submissions: 388K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "Let's take LeetCode contest"
 * 输出："s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入： s = "God Ding"
 * 输出："doG gniD"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * s 包含可打印的 ASCII 字符。
 * s 不包含任何开头或结尾空格。
 * s 里 至少 有一个词。
 * s 中的所有单词都用一个空格隔开。
 * 
 * 
 */

// @lc code=start

static void swap(char *a, char *b)
{
        char c = *a;
        *a = *b, *b = c;
}

/*
 * reverse [l, r)
 */
static void reverse(char *l, char *r)
{
        while (l < r) swap(l++, --r);
}

char * reverseWords(char *s)
{
        char *l = s;
        char *r = s;

        while(*r != '\0') {
                while (*r != '\0' && *r == ' ') r++;
                l = r;
                while (*r != '\0' && *r != ' ') r++;
                reverse(l, r);
        }

        return s;
}
// @lc code=end


