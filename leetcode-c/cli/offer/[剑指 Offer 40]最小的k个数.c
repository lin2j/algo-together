//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [3,2,1], k = 2
//输出：[1,2] 或者 [2,1]
// 
//
// 示例 2： 
//
// 输入：arr = [0,1,2,1], k = 1
//输出：[0] 
//
// 
//
// 限制： 
//
// 
// 0 <= k <= arr.length <= 10000 
// 0 <= arr[i] <= 10000 
// 
//
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 472 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


static void swap(int *arr, int i, int j)
{
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
}

static int * quick_sort(int *arr, int l, int r, int k)
{
        int i = l, j = r;
        while(i < j) {
                while(i < j && arr[j] >= arr[l]) j--;
                while(i < j && arr[i] <= arr[l]) i++;
                swap(arr, i, j);
        }
        swap(arr, i, l);
        if (i > k) {
                return quick_sort(arr, l, i - 1, k);
        }
        if (i < k) {
                return quick_sort(arr, i + 1, r, k);
        }
        int len = sizeof(int) * k;
        int *ans = (int *)malloc(len);
        memcpy(ans, arr, len);
        return ans;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * getLeastNumbers(int *arr, int arr_size,
                      int k, int *return_size)
{
        *return_size = 0;
        if (arr_size == 0 || k == 0)
                return NULL;

        *return_size = k;
        if (k <= arr_size) return arr;

        return quick_sort(arr, 0, arr_size - 1, k);
}

//leetcode submit region end(Prohibit modification and deletion)
