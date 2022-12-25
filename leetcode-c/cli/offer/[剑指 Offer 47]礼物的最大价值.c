//在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直
//到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？ 
//
// 
//
// 示例 1: 
//
// 输入: 
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 12
//解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物 
//
// 
//
// 提示： 
//
// 
// 0 < grid.length <= 200 
// 0 < grid[0].length <= 200 
// 
//
// Related Topics 数组 动态规划 矩阵 👍 322 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int maxValue(int **grid, int grid_size, int *grid_col_size)
{
        // G(i, j) = Max(G(i-1, j), G(i, j-1)) + grid[i][j]
        int row = grid_size;
        int col = grid_col_size[0];
        for(int j = 1; j < col; j++)
                grid[0][j] += grid[0][j-1]; // first row
        for(int i = 1; i < row; i++)
                grid[i][0] += grid[i-1][0]; // first col
        for(int i = 1; i < row; i++)
                for(int j = 1; j < col; j++)
                        grid[i][j] += MAX(grid[i-1][j], grid[i][j-1]);

        return grid[row-1][col-1];
}

//leetcode submit region end(Prohibit modification and deletion)
