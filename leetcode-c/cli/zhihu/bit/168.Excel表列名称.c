/*
 * @lc app=leetcode.cn id=168 lang=c
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (43.84%)
 * Total Accepted:    134K
 * Total Submissions: 305.8K
 * Testcase Example:  '1'
 *
 * 给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如：
 * 
 * 
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28 
 * ...
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：columnNumber = 1
 * 输出："A"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：columnNumber = 28
 * 输出："AB"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：columnNumber = 701
 * 输出："ZY"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：columnNumber = 2147483647
 * 输出："FXSHRXW"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start
char * convertToTitle(int column_number)
{
        int k = 0;
        char *result = malloc(sizeof(char) * 8);

        int n = column_number;
        while (n != 0) {
                n--;
                result[k++] = n % 26 + 'A';
                n /= 26;
        }

        int i = 0, j = k - 1;
        while (i < j) {
                char c = result[i];
                result[i] = result[j];
                result[j] = c;
                i++, j--;
        }
        result[k] = '\0';

        return result;
}
// @lc code=end

