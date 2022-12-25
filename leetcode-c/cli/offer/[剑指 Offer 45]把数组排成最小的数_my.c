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

static int compare(char *s1, char *s2) {
        char s1s2[22];
        char s2s1[22];

        sprintf(s1s2, "%s%s", s1, s2);
        sprintf(s2s1, "%s%s", s2, s1);

        return strcmp(s1s2, s2s1);
}

static void swap(char **i, char **j)
{
        char *tmp = *i;
        *i = *j;
        *j = tmp;
}

static void quick_sort(char **nums, int l, int r)
{
        if (l >= r) return;
        int i = l, j = r;
        while(i < j) {
                while(i < j && compare(nums[j], nums[l]) >= 0) j--;
                while(i < j && compare(nums[i], nums[l]) <= 0) i++;
                swap(&nums[i], &nums[j]);
        }
        swap(&nums[i], &nums[l]);

        quick_sort(nums, l, i - 1);
        quick_sort(nums, i + 1, r);
}

char* minNumber(int* nums, int nums_size)
{
        int len = 0;
        char **nums_str = (char **)malloc(sizeof(char *) * nums_size);
        memset(nums_str, 0, nums_size);
        char tmp[11] = {0};
        int tmp_len;
        for (int i = 0; i < nums_size; ++i) {
                sprintf(tmp, "%d", nums[i]);
                tmp_len = strlen(tmp);
                // the 1 in "tmp_len + 1" is used for saving the '\0'
                nums_str[i] = (char *)calloc(tmp_len + 1, sizeof(char));
                memcpy(nums_str[i], tmp, tmp_len);

                len += tmp_len;
                memset(tmp, 0, 11);
        }
        quick_sort(nums_str, 0, nums_size - 1);

        // why the length of the ans is "sizeof(char) * len + 2" ?
        // because the process of strcat will produce a '\0' character,
        // so one of the character is used for saving '\0'
        char *ans = (char *)malloc(sizeof(char) * len + 2);
        memset(ans, 0, sizeof(char) * len + 2);
        for (int i = 0; i < nums_size; i++) {
                strcat(ans, nums_str[i]);
        }

        for (int i = 0; i < nums_size; ++i)
                free(nums_str[i]);
        free(nums_str);

        return ans;
}

//leetcode submit region end(Prohibit modification and deletion)
