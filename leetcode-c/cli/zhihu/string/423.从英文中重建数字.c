/*
 * @lc app=leetcode.cn id=423 lang=c
 *
 * [423] 从英文中重建数字
 *
 * https://leetcode.cn/problems/reconstruct-original-digits-from-english/description/
 *
 * algorithms
 * Medium (60.94%)
 * Likes:    192
 * Dislikes: 0
 * Total Accepted:    38.3K
 * Total Submissions: 62.8K
 * Testcase Example:  '"owoztneoer"'
 *
 * 给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。
 * 按 升序 返回原始的数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "owoztneoer"
 * 输出："012"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "fviefuro"
 * 输出："45"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] 为 ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"]
 * 这些字符之一
 * s 保证是一个符合题目要求的字符串
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start

/*
 * 官方题解：https://leetcode.cn/problems/reconstruct-original-digits-from-english/solution/cong-ying-wen-zhong-zhong-jian-shu-zi-by-9g1r/
 *
 */
char * originalDigits(char *s)
{
        int char_cnt[26] = {0};
        for (int i = 0; s[i] != '\0'; i++)
                char_cnt[s[i] - 'a']++;

        int total = 0;
        int num_cnt[10] = {0};
        num_cnt[0] = char_cnt['z' - 'a'];
        num_cnt[2] = char_cnt['w' - 'a'];
        num_cnt[4] = char_cnt['u' - 'a'];
        num_cnt[6] = char_cnt['x' - 'a'];
        num_cnt[8] = char_cnt['g' - 'a'];

        total += num_cnt[0] + num_cnt[2] + num_cnt[4] + num_cnt[6] + num_cnt[8];

        num_cnt[3] = char_cnt['h' - 'a'] - num_cnt[8];
        num_cnt[5] = char_cnt['f' - 'a'] - num_cnt[4];
        num_cnt[7] = char_cnt['s' - 'a'] - num_cnt[6];

        total += num_cnt[3] + num_cnt[5] + num_cnt[7];

        num_cnt[1] = char_cnt['o' - 'a'] - num_cnt[0] - num_cnt[2] - num_cnt[4];
        num_cnt[9] = char_cnt['i' - 'a'] - num_cnt[5] - num_cnt[6] - num_cnt[8];

        total += num_cnt[1] + num_cnt[9];

        char *result = malloc(sizeof(char) * (total + 1));

        int idx = 0;
        for (int i = 0; i < 10; i++)
                for (int j = 0; j < num_cnt[i]; j++)
                        result[idx++] = i + '0';
        result[idx] = '\0';

        return result;
}
// @lc code=end


