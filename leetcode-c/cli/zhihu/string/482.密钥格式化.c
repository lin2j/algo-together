/*
 * @lc app=leetcode.cn id=482 lang=c
 *
 * [482] 密钥格式化
 *
 * https://leetcode.cn/problems/license-key-formatting/description/
 *
 * algorithms
 * Easy (46.82%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    54.2K
 * Total Submissions: 115.6K
 * Testcase Example:  '"5F3Z-2e-9-w"\n4'
 *
 * 给定一个许可密钥字符串 s，仅由字母、数字字符和破折号组成。字符串由 n 个破折号分成 n + 1 组。你也会得到一个整数 k 。
 * 
 * 我们想要重新格式化字符串 s，使每一组包含 k 个字符，除了第一组，它可以比 k
 * 短，但仍然必须包含至少一个字符。此外，两组之间必须插入破折号，并且应该将所有小写字母转换为大写字母。
 * 
 * 返回 重新格式化的许可密钥 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：S = "5F3Z-2e-9-w", k = 4
 * 输出："5F3Z-2E9W"
 * 解释：字符串 S 被分成了两个部分，每部分 4 个字符；
 * 注意，两个额外的破折号需要删掉。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：S = "2-5g-3-J", k = 2
 * 输出："2-5G-3J"
 * 解释：字符串 S 被分成了 3 个部分，按照前面的规则描述，第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 只包含字母、数字和破折号 '-'.
 * 1 <= k <= 10^4
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// @lc code=start

static void reverse(char *l, char *r)
{
        while(l < r) {
                char c = *l;
                *l = *r;
                *r = c;

                l++;
                r--;
        }
}

char * licenseKeyFormatting(char *s, int k)
{
        int len_s = strlen(s);
        int cnt = 0;

        for (int i = 0; i < len_s; i++) {
                if (s[i] == '-') {
                        continue;
                }
                if (s[i] >= 'a' && s[i] <= 'z')
                        s[i] -= 32;
                s[cnt++] = s[i];
        }

        if (cnt == 0) return "";

        int len_res = cnt + cnt / k + 1;
        char *result = malloc(sizeof(char) * len_res);

        int i = 0, c = 0;
        cnt--;
        while (cnt >= 0) {
                c++;
                result[i++] = s[cnt];
                if (c % k == 0)
                        result[i++] = '-';
                cnt--;
        }
        if (result[i - 1] == '-') i--;
        result[i] = '\0';

        reverse(&result[0], &result[i - 1]);

        return result;
}
// @lc code=end


