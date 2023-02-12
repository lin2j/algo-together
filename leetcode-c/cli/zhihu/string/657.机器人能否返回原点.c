/*
 * @lc app=leetcode.cn id=657 lang=c
 *
 * [657] 机器人能否返回原点
 *
 * https://leetcode.cn/problems/robot-return-to-origin/description/
 *
 * algorithms
 * Easy (78.82%)
 * Likes:    242
 * Dislikes: 0
 * Total Accepted:    100.2K
 * Total Submissions: 127.1K
 * Testcase Example:  '"UD"'
 *
 * 在二维平面上，有一个机器人从原点 (0, 0) 开始。给出它的移动顺序，
 * 判断这个机器人在完成移动后是否在 (0, 0) 处结束。
 * 
 * 移动顺序由字符串 moves 表示。字符 move[i] 表示其第 i 次移动。
 * 机器人的有效动作有 R（右），L（左），U（上）和 D（下）。
 * 
 * 如果机器人在完成所有动作后返回原点，则返回 true。否则，返回 false。
 * 
 * 注意：机器人“面朝”的方向无关紧要。 “R” 将始终使机器人向右移动一次，“L” 将始终向左移动等。此外，假设每次移动机器人的移动幅度相同。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: moves = "UD"
 * 输出: true
 * 解释：机器人向上移动一次，然后向下移动一次。所有动作都具有相同的幅度，因此它最终回到它开始的原点。因此，我们返回 true。
 * 
 * 示例 2:
 * 
 * 
 * 输入: moves = "LL"
 * 输出: false
 * 解释：机器人向左移动两次。它最终位于原点的左侧，距原点有两次 “移动” 的距离。我们返回 false，因为它在移动结束时没有返回原点。
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= moves.length <= 2 * 10^4
 * moves 只包含字符 'U', 'D', 'L' 和 'R'
 * 
 * 
 */
#include <stdbool.h>

// @lc code=start


/*
 * 模拟
 *
 * 用两个变量 x、y 表示机器人当前在（x、y）位置，
 *
 * 初始 (x, y) 为 (0, 0)，规定
 * 
 * 当遇到 U 时，x += 1
 * 当遇到 D 时，x -= 1
 * 当遇到 R 时，y += 1
 * 当遇到 L 时，y -= 1
 *
 * 最终如果 (x, y) 为 (0, 0) 则表示可以回到原点
 */
bool judgeCircle(char *moves)
{
        int x = 0, y = 0;

        for (int i = 0; moves[i] != '\0'; i++)
                switch (moves[i]) {
                        case 'U': x++; break;
                        case 'D': x--; break;
                        case 'R': y++; break;
                        case 'L': y--; break;
                        default: break;
                }

        return x == 0 && y == 0;

}
// @lc code=end


