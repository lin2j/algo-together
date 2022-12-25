////找出数组中重复的数字。 
////
//// 
////在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次
//。请
////找出数组中任意一个重复的数字。 
////
//// 示例 1： 
////
//// 输入：
////[2, 3, 1, 0, 2, 5, 3]
////输出：2 或 3 
//// 
////
//// 
////
//// 限制： 
////
//// 2 <= n <= 100000 
//// Related Topics 数组 哈希表 排序 👍 895 👎 0
//


//leetcode submit region begin(Prohibit modification and deletion)

static void swap_int(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

int findRepeatNumber(int* nums, int nums_size){
	if (nums == NULL || nums_size == 0)
		return -1;

	for (int i = 0; i < nums_size;) {
		if (nums[i] == i) {
			i++;
			continue;
		}
		/* nums[a] must not equal a,
		   or a is the target number */
		int a = nums[i];
		if (nums[a] == a)
			return a;
		swap_int(&nums[a], &nums[i]);
	}

	return -1;
}

//leetcode submit region end(Prohibit modification and deletion)
