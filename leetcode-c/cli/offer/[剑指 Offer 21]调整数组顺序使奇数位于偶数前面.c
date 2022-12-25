//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。 
//
// 
//
// 示例： 
//
// 
//输入：nums = [1,2,3,4]
//输出：[1,3,2,4] 
//注：[3,1,2,4] 也是正确的答案之一。 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 50000 
// 0 <= nums[i] <= 10000 
// 
// Related Topics 数组 双指针 排序 👍 245 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

static void swap(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(int *nums, int nums_size, int *return_size){
	*return_size = nums_size;
	if (nums_size == 0)
		return nums;

	int left = 0, right = nums_size - 1;
	while(left < right) {
		while(left < right && (nums[right] & 1) == 0)
			right--;
		while(left < right && (nums[left] & 1) == 1)
			left++;

		swap(&nums[left], &nums[right]);
	}
	return nums;
}

//leetcode submit region end(Prohibit modification and deletion)
