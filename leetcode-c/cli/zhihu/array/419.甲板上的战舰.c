/*
 * @lc app=leetcode.cn id=419 lang=c
 *
 * [419] 甲板上的战舰
 *
 * https://leetcode.cn/problems/battleships-in-a-board/description/
 *
 * algorithms
 * Medium (78.37%)
 * Likes:    231
 * Dislikes: 0
 * Total Accepted:    41.9K
 * Total Submissions: 53.4K
 * Testcase Example:  '[["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]'
 *
 * 给你一个大小为 m x n 的矩阵 board 表示甲板，其中，每个单元格可以是一艘战
 * 舰 'X' 或者是一个空位 '.' ，返回在甲板 board 上放置的 战舰 的数量。
 * 
 * 战舰 只能水平或者垂直放置在 board 上。换句话说，战舰只能按 1 x k（1 行，
 * k 列）或 k x 1（k 行，1 列）的形状建造，其中 k 可以是任意大小。两艘战舰之
 * 间至少有一个水平或垂直的空位分隔 （即没有相邻的战舰）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["."]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] 是 '.' 或 'X'
 * 
 * 
 * 
 * 
 * 进阶：你可以实现一次扫描算法，并只使用 O(1) 额外空间，
 * 并且不修改 board 的值来解决这个问题吗？
 * 
 */

// @lc code=start


/*
 * 给你一个 m x n 的棋盘，棋盘格子中的 "X" 代表战舰， "." 为空， 返回
 * 棋盘中“战舰群”的数量。
 * “战舰群”只能垂直、水平摆放（也就是说，“战舰群”只能是由 k 艘战舰组成
 * 的一行，或者是由 k 艘战舰组成的一列），每个“战舰群”都不会相邻。
 *
 *
 * 求多少个战舰群
 *
 *
 * 遍历二位board数组：找寻战舰的头部
 * （这里将战舰靠近上侧、靠近左侧的的一个'X' 作为它的头)
 */
int countBattleships(char **board, int board_size, int *board_col_size)
{
        int m = board_size;
        int n = board_col_size[0];

        int ans = 0;
        for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                        // 排除空位
                        if (board[i][j] == '.') continue;
                        // 排除非头部
                        if (i > 0 && board[i-1][j] == 'X') continue;
                        if (j > 0 && board[i][j-1] == 'X') continue;

                        ans++;
                }
        }
        return ans;
}
// @lc code=end


