/*
 * @lc app=leetcode.cn id=165 lang=c
 *
 * [165] 比较版本号
 *
 * https://leetcode.cn/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (51.94%)
 * Likes:    347
 * Dislikes: 0
 * Total Accepted:    141.2K
 * Total Submissions: 271.9K
 * Testcase Example:  '"1.01"\n"1.001"'
 *
 * 给你两个版本号 version1 和 version2 ，请你比较它们。
 * 
 * 版本号由一个或多个修订号组成，各修订号由一个 '.' 连接。每个修订号
 * 由 多位数字 组成，可能包含 前导零。每个版本号至少包含一个字符。修
 * 订号从左到右编号，下标从 0 开始，最左边的修订号下标为 0 ，下一个
 * 修订号下标为 1 ，以此类推。例如，2.5.33 和 0.1 都是有效的版本号。
 * 
 * 比较版本号时，请按从左到右的顺序依次比较它们的修订号。比较修订号时，
 * 只需比较 忽略任何前导零后的整数值 。也就是说，修订号 1 和修订号 001 相等。
 * 如果版本号没有指定某个下标处的修订号，则该修订号视为 0 。例如，版本 1.0 小
 * 于版本 1.1 ，因为它们下标为 0 的修订号相同，而下标为 1 的修订号分别为 0 和
 * 1 ，0 < 1 。
 * 
 * 返回规则如下：
 * 
 * 
 * 如果 version1 > version2 返回 1，
 * 如果 version1 < version2 返回 -1，
 * 除此之外返回 0。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：version1 = "1.01", version2 = "1.001"
 * 输出：0
 * 解释：忽略前导零，"01" 和 "001" 都表示相同的整数 "1"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：version1 = "1.0", version2 = "1.0.0"
 * 输出：0
 * 解释：version1 没有指定下标为 2 的修订号，即视为 "0"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：version1 = "0.1", version2 = "1.1"
 * 输出：-1
 * 解释：version1 中下标为 0 的修订号是 "0"，version2 中下标为 0 的修订号是 "1" 。0 < 1，所以 version1 <
 * version2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= version1.length, version2.length <= 500
 * version1 和 version2 仅包含数字和 '.'
 * version1 和 version2 都是 有效版本号
 * version1 和 version2 的所有修订号都可以存储在 32 位整数 中
 * 
 * 
 */

#include <stdio.h>
#include <string.h>

// @lc code=start

#define END(c) ((c) == '.' || (c) == '\0')

// 返回 part 到 '.' 或者 '\0' 的长度
static int get_number(char *part, int *num)
{
        int n = 0, k = 0;
        while (!END(part[k])) {
                // 先减 '0' 很重要
                // 假设 n = 214748364 对于 n * 10 + part[k] - '0' 来说
                // 在计算时，会先计算 n * 10 + part[k]，这里会溢出
                // 因为 part[k] 实际是一个字符，实际数值是大于 7 的
                // 因此 n * 10 + part[k] 超过 32 整型的表达范围，溢出        
                n = n * 10 - '0' + part[k] ;
                k++;
        }
        *num = n;
        return k;
}

int compareVersion(char *version1, char *version2)
{
        int n1 = strlen(version1);
        int n2 = strlen(version2);

        int i1 = 0, i2 = 0;
        int v1 = 0, v2 = 0;
        while (i1 < n1 && i2 < n2) {
                int l1 = get_number(version1 + i1, &v1);
                int l2 = get_number(version2 + i2, &v2);

                if (v1 > v2)
                        return 1;
                else if (v1 < v2)
                        return -1;

                i1 += l1 + 1;
                i2 += l2 + 1;
        }

        while (i1 < n1) {
                int l1 = get_number(version1 + i1, &v1);

                if (v1 > 0) 
                        return 1;
                i1 += l1 + 1;

        }

        while (i2 < n2) {
                int l2 = get_number(version2 + i2, &v2);

                if (v2 > 0) 
                        return -1;

                i2 += l2 + 1;
        }

        return 0;
}
// @lc code=end


