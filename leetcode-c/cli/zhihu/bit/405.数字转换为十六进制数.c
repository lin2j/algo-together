/*
 * @lc app=leetcode.cn id=405 lang=c
 *
 * [405] 数字转换为十六进制数
 *
 * https://leetcode.cn/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (54.74%)
 * Likes:    278
 * Dislikes: 0
 * Total Accepted:    64.2K
 * Total Submissions: 117.3K
 * Testcase Example:  '26'
 *
 * 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
 * 
 * 注意:
 * 
 * 
 * 十六进制中所有字母(a-f)都必须是小写。
 * 
 * 十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
 * 给定的数确保在32位有符号整数范围内。
 * 不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入:
 * 26
 * 
 * 输出:
 * "1a"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入:
 * -1
 * 
 * 输出:
 * "ffffffff"
 * 
 * 
 */
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

// @lc code=start

// 2^32
static const long OFFSET = 0x100000000;

/*
 * 对于负数的 num，我们需要先在 num 基础上
 * 加上 2^32 的偏移量，再进行进制转换
 */
char * toHex(int _num)
{
        if (_num == 0) return "0";

        long num = _num;
        if (num < 0) num += OFFSET;

        int idx = 0;
        char *result = malloc(sizeof(char) * 11);
        while (num != 0) {
                long u = num % 16;
                num /= 16;

                result[idx++] = u < 10 ? u + '0' : (u - 10 + 'a'); 
        }

        // 反转
        int i = 0, j = idx - 1;
        while (i < j) {
                char c = result[i];
                result[i] = result[j];
                result[j] = c;
                i++, j--;
        }
        result[idx] = '\0';

        return result;
}
// @lc code=end


