//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。 
//
// 
//
// 示例 1: 
//
// 输入: [7,5,6,4]
//输出: 5 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
//
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 822 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

int ans;

static void merge(int *nums, int *tmp, int l, int mid, int r)
{
        int i = l, j = mid + 1, k = l;
        while (i <= mid && j <= r) {
                if (nums[i] <= nums[j]) {
                        tmp[k++] = nums[i++];
                } else {
                        ans += mid - i + 1;
                        tmp[k++] = nums[j++];
                }
        }
        while (i <= mid) tmp[k++] = nums[i++];
        while (j <= r) tmp[k++] = nums[j++];
        memcpy(nums+l, tmp+l, sizeof(int) * (r-l+1));
}

static void merge_sort(int *nums, int *tmp, int l, int r)
{
        if (l >= r) return;
        int mid = (l + r) / 2;
        merge_sort(nums, tmp, l, mid);
        merge_sort(nums, tmp, mid + 1, r);
        merge(nums, tmp, l, mid, r);
}

int reversePairs(int *nums, int nums_size)
{
        if (nums_size == 0) return 0;
        ans = 0;
        int *tmp = (int *)malloc(sizeof(int) * nums_size);
        merge_sort(nums, tmp, 0, nums_size - 1);
        free(tmp);
        return ans;
}

//leetcode submit region end(Prohibit modification and deletion)
