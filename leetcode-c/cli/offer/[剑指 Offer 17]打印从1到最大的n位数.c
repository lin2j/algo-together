//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。 
//
// 示例 1: 
//
// 输入: n = 1
//输出: [1,2,3,4,5,6,7,8,9]
// 
//
// 
//
// 说明： 
//
// 
// 用返回一个整数列表来代替打印 
// n 为正整数 
// 
// Related Topics 数组 数学 👍 236 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* printNumbers(int n, int* return_size)
{

	int p =	pow(10, n);
	*return_size = p - 1;
	int *arr = (int *)malloc(sizeof(int) * (*return_size));
	for(int i = 1; i <= *return_size; i++) {
		arr[i-1] = i;
	}
	return arr;
}

//leetcode submit region end(Prohibit modification and deletion)
