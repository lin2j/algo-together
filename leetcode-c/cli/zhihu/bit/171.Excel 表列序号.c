/*
 * @lc app=leetcode.cn id=171 lang=c
 *
 * [171] Excel 表列序号
 *
 * https://leetcode.cn/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (71.36%)
 * Likes:    379
 * Dislikes: 0
 * Total Accepted:    161.2K
 * Total Submissions: 225.9K
 * Testcase Example:  '"A"'
 *
 * 给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。返回 该列名称对应的列序号 。
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
 * 示例 1:
 * 
 * 
 * 输入: columnTitle = "A"
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: columnTitle = "AB"
 * 输出: 28
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: columnTitle = "ZY"
 * 输出: 701
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= columnTitle.length <= 7
 * columnTitle 仅由大写英文组成
 * columnTitle 在范围 ["A", "FXSHRXW"] 内
 * 
 * 
 */

// @lc code=start


int titleToNumber(char *column_title)
{
        int result = 0;

        char *p = column_title;
        while (*p != '\0') {
                int u = *p - 'A' + 1;
                result = result * 26 + u;
                p++;
        }

        return result;
}
// @lc code=end


