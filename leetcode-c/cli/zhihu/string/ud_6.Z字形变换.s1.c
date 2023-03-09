/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 *
 * https://leetcode.cn/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (52.09%)
 * Likes:    1957
 * Dislikes: 0
 * Total Accepted:    532.9K
 * Total Submissions: 1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "PAYPALISHIRING", numRows = 3
 * 输出："PAHNAPLSIIGYIR"
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "PAYPALISHIRING", numRows = 4
 * 输出："PINALSIGYAHRPI"
 * 解释：
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "A", numRows = 1
 * 输出："A"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由英文字母（小写和大写）、',' 和 '.' 组成
 * 1 
 * 
 * 
 */
#include <stdlib.h>
#include <string.h>

// @lc code=start

/*
 * 设 r = num_rows，n = strlen(s)
 * 则当 r = 1 (只有一行）或者 r >= n（只有一列）时，直接返回 s
 *
 * 而其他情况。
 *
 * 根据题意，变换时会向下填充 r 个字符，然后向上填充 r - 2 个字符，
 * 将这个成为一个周期 t，则一个周期包含 t = r + r - 2 = 2r - 2 个字符，占用 
 * 1 + r - 2 = r - 1 列，共有 n/t（向上取整）个周期。
 *
 * 最终结果矩阵的列数则为 n/t * (r-1) 列。
 *
 * 遍历 s，设当前索引为 i，当 i % t < r - 1 时，向下移动，否则向右上移动。
 *
 * 基于上面对周期的推算，可以尝试找出 s 中每个字符变换后的位置 idx
 *
 * 0             0+t                  0+2t                   0+3t
 * 1      t-1    1+t          0+2t-1  1+2t          0+3t-1   1+3t
 * 2  t-2        2+t  0+2t-2          2+2t  0+3t-2           2+3t  
 * 3             3+t                  3+2t                   3+3t
 *
 */
char * convert(char *s, int num_rows)
{
        int r = num_rows, n = strlen(s);
        if (r == 1 || r >= n)
                return s;

}
// @lc code=end


