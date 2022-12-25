//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一
//格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但
//它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？ 
//
// 
//
// 示例 1： 
//
// 输入：m = 2, n = 3, k = 1
//输出：3
// 
//
// 示例 2： 
//
// 输入：m = 3, n = 1, k = 0
//输出：1
// 
//
// 提示： 
//
// 
// 1 <= n,m <= 100 
// 0 <= k <= 20 
// 
// Related Topics 深度优先搜索 广度优先搜索 动态规划 👍 538 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

static int sum_of_digit(int n)
{
	int sum = 0;
	while (n > 0) {
		sum += (n % 10);
		n /= 10;
	}

	return sum;
}

static int __move(int m, int n, int x, int y,
		   int k, bool **visited)
{
	if (x >= m || y >= n || visited[x][y] == true)
		return 0;

	int sum = (sum_of_digit(x) + sum_of_digit(y));
	if (sum > k)
		return 0;

	visited[x][y] = true;
	return 1 + __move(m, n, x + 1, y, k, visited)
			+ __move(m, n, x, y + 1, k, visited);
}

int movingCount(int m, int n, int k)
{
	if (k < 0)
		return -1;

	bool **visited = (bool **)malloc(sizeof(bool *) * m);
	for (int i = 0; i < m; i++) {
		visited[i] = (bool *)calloc(n, sizeof(bool));
	}
	return __move(m, n, 0, 0, k, visited);
}

//leetcode submit region end(Prohibit modification and deletion)
