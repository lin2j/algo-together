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
 * 最终结果矩阵 mat 的列数则为 n/t * (r-1) 列。
 *
 * 遍历 s，设当前索引为 i，当 i % t < r - 1 时，向下移动，否则向右上移动。
 *
 * 优化：上述方法中 mat 有大量的位置存储的是 '\0’，空间利用率，如果使用的
 *       语言有动态字符串，则可以通过则每一行的尾部追加字符的方式，避免存
 *       在大量的 '\0'，这样可以将空间复杂度降低到 O(n)
 *
 * T(n): O(rn)
 * S(n): O(rn)
 */
char * convert(char *s, int num_rows)
{
        int r = num_rows, n = strlen(s);
        if (r == 1 || r >= n)
                return s;

        int t = 2 * r - 2;
        int c = (n / t + 1) * (r - 1);
        char **mat = malloc(sizeof(char *) * r);
        for (int i = 0; i < r; i++) {
                mat[i] = malloc(sizeof(char) * c);
                memset(mat[i], 0, sizeof(char) * c);
        }

        int x = 0, y = 0;
        for (int i = 0; s[i] != '\0'; i++) {
                mat[x][y] = s[i];
                if (i % t < r - 1) {
                        // 向下移动
                        x++;
                } else {
                        // 向上移动
                        x--;
                        y++;
                }
        }

        int pos = 0;
        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        if (mat[i][j] != 0)
                                s[pos++] = mat[i][j];
                }
                free(mat[i]);
        }

        free(mat);

        return s;
}
// @lc code=end


