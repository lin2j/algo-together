//输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。 
//
// 
//
// 示例 1: 
//
// 输入: [10,2]
//输出: "102" 
//
// 示例 2: 
//
// 输入: [3,30,34,5,9]
//输出: "3033459" 
//
// 
//
// 提示: 
//
// 
// 0 < nums.length <= 100 
// 
//
// 说明: 
//
// 
// 输出结果可能非常大，所以你需要返回一个字符串而不是整数 
// 拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0 
// 
//
// Related Topics 贪心 字符串 排序 👍 524 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

//static int compare(int s1, int s2) {
//        char s1s2[22];
//        char s2s1[22];
//
//        sprintf(s1s2, "%d%d", s1, s2);
//        sprintf(s2s1, "%d%d", s2, s1);
//
//        return strcmp(s1s2, s2s1);
//}
//
//static void swap(int *i, int *j)
//{
//        int tmp = *i;
//        *i = *j;
//        *j = tmp;
//}
//
//static void quick_sort(int *nums, int l, int r)
//{
//        if (l >= r) return;
//        int i = l, j = r;
//        while(i < j) {
//                while(i < j && compare(nums[j], nums[l]) >= 0) j--;
//                while(i < j && compare(nums[i], nums[l]) <= 0) i++;
//                swap(&nums[i], &nums[j]);
//        }
//        swap(&nums[i], &nums[l]);
//
//        quick_sort(nums, l, i - 1);
//        quick_sort(nums, i + 1, r);
//}
//
//char* minNumber(int* nums, int nums_size)
//{
//        quick_sort(nums, 0, nums_size - 1);
//
//        char *ans = (char *)malloc(sizeof(char) * 1100 + 1);
//        memset(ans, 0, sizeof(sizeof(char) * 1100 + 1));
//        char *p = ans;
//        for (int i = 0; i < nums_size; i++)
//                p += sprintf(p, "%d", nums[i]);
//        *p = '\0';
//
//        return ans;
//}

int compare(const void *a, const void *b)
{
        char num1[24];
        char num2[24];

        sprintf(num1, "%d%d", *(int *)a, *(int *)b);
        sprintf(num2, "%d%d", *(int *)b, *(int *)a);
        return strcmp(num1, num2);
}

char* minNumber(int* nums, int numsSize){
        char *res = (char *)malloc(sizeof(char) * 1200);
        char *p = res;

        qsort(nums, numsSize, sizeof(int), compare);
        for (int i = 0; i < numsSize; i++)
                p += sprintf(p, "%d", nums[i]);
        *p = '\0';
        return res;
}

//leetcode submit region end(Prohibit modification and deletion)
