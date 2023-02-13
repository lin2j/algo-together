/*
 * @lc app=leetcode.cn id=551 lang=c
 *
 * [551] 学生出勤记录 I
 *
 * https://leetcode.cn/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (56.76%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    75.3K
 * Total Submissions: 132.7K
 * Testcase Example:  '"PPALLP"'
 *
 * 给你一个字符串 s 表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤
 * 情况（缺勤、迟到、到场）。记录中只含下面三种字符：
 * 
 * 
 * 'A'：Absent，缺勤
 * 'L'：Late，迟到
 * 'P'：Present，到场
 * 
 * 
 * 如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：
 * 
 * 
 * 按 总出勤 计，学生缺勤（'A'）严格 少于两天。
 * 学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
 * 
 * 
 * 如果学生可以获得出勤奖励，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "PPALLP"
 * 输出：true
 * 解释：学生缺勤次数少于 2 次，且不存在 3 天或以上的连续迟到记录。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "PPALLL"
 * 输出：false
 * 解释：学生最后三天连续迟到，所以不满足出勤奖励的条件。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s[i] 为 'A'、'L' 或 'P'
 * 
 * 
 */
#include <stdbool.h>

// @lc code=start

/*
 * 当缺席次数大于 1 时，返回 false
 *
 * 迟到次数初始为 0，
 * 循环判断
 * 每次遇到迟到时，先判断迟到次数是否为 2
 * 如果已经迟到 2 次，则返回 false，
 * 否则迟到次数 +1，然后继续遍历
 * 如果遍历到到席，则迟到次数置 0
 *
 * T(n): O(n)
 * S(n): O(1)
 */
bool checkRecord(char *s)
{
        int absent_cnt = 0;
        int late_cnt = 0;

        for (int i = 0; s[i] != '\0'; i++) {
                char c = s[i];
                if (c == 'A') {
                        absent_cnt++;
                        if (absent_cnt > 1)
                                return false;
                } 

                if (c == 'L' && late_cnt < 3) {
                        late_cnt++;
                        if (late_cnt > 2)
                                return false;

                        continue;
                }

                late_cnt = 0;
        }

        return true;
}
// @lc code=end


