/*
 * @lc app=leetcode.cn id=598 lang=c
 *
 * [598] 范围求和 II
 *
 * https://leetcode.cn/problems/range-addition-ii/description/
 *
 * algorithms
 * Easy (57.66%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    50.8K
 * Total Submissions: 88K
 * Testcase Example:  '3\n3\n[[2,2],[3,3]]'
 *
 * 给你一个 m x n 的矩阵 M ，初始化时所有的 0 和一个操作数组 op ，其中 
 * ops[i] = [ai, bi] 意味着当所有的 0 <= x < ai 和 0 <= y < bi 时， 
 * M[x][y] 应该加 1。
 * 
 * 在 执行完所有操作后 ，计算并返回 矩阵中最大整数的个数 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: m = 3, n = 3，ops = [[2,2],[3,3]]
 * 输出: 4
 * 解释: M 中最大的整数是 2, 而且 M 中有4个值为2的元素。因此返回 4。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: m = 3, n = 3, ops =
 * [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
 * 输出: 4
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: m = 3, n = 3, ops = []
 * 输出: 9
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 
 * 
 * 1 <= m, n <= 4 * 10^4
 * 0 <= ops.length <= 10^4
 * ops[i].length == 2
 * 1 <= ai <= m
 * 1 <= bi <= n
 * 
 * 
 */

// @lc code=start

#define MIN(a, b) ((a) > (b) ? (b) : (a))

/*
 * 首先 (0,0) 这个位置是不管如何都会进行操作的，因此该位置最终将是最大的数字
 * (如果 ops 数组为空的话，则这个二维数组的数字都为最大的)
 *
 *
 * ops 的 a 的最小值 mina 代表了横轴上所有小于 a 的位置都可能有一次操作机会
 * ops 的 b 的最小值 minb 代表了竖轴上所有小于 b 的位置都可能有一次操作机会
 *
 * 可以肯定的是，同时小于 a 和 b 的位置一定会有一次操作，因此 a * b 的面积
 * 就是最大数的个数
 */
int maxCount(int m, int n, int **ops, 
             int ops_size, int *ops_col_size){
        int mina = m;
        int minb = n;

        for (int i = 0; i < ops_size; i++) {
                mina = MIN(mina, ops[i][0]);
                minb = MIN(minb, ops[i][1]);
        }
        return mina * minb;
}
// @lc code=end


