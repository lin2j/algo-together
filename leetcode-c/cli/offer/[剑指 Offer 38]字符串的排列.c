//输入一个字符串，打印出该字符串中字符的所有排列。 
//
// 
//
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。 
//
// 
//
// 示例: 
//
// 输入：s = "abc"
//输出：["abc","acb","bac","bca","cab","cba"]
//
//
// 
//
// 限制： 
//
// 1 <= s 的长度 <= 8 
//
// Related Topics 字符串 回溯 👍 594 👎 0

//leetcode submit region begin(Prohibit modification and deletion)

#define MAX_LEN 8

char **ans;

static void swap(char *i, char *j)
{
        char tmp = *i;
        *i = *j;
        *j = tmp;
}

static bool array_contains(char arr[MAX_LEN], char c)
{
        for (int i = 0; i < MAX_LEN; i++)
                if (arr[i] == c)
                        return true;
        return false;
}

static void dfs(char *s, int s_len, int x, int *return_size)
{
        if (x == s_len) {
                ans[*return_size] = (char *)malloc(s_len + 1);
                memcpy(ans[*return_size], s, sizeof(char) * s_len);
                ans[*return_size][s_len] = '\0';
                *return_size += 1;
                return;
        }

        int k = 0;
        char set[MAX_LEN] = {0};
        for(int i = x; i < s_len; i++) {
                if (array_contains(set, s[i]))
                        continue;

                swap(&s[i], &s[x]);
                dfs(s, s_len, x + 1, return_size);
                swap(&s[i], &s[x]);
                set[k++] = s[i];
        }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** permutation(char *s, int *return_size)
{
    *return_size = 0;
    if (s == NULL)
        return NULL;

    int s_len = (int)strlen(s);
    int max = 1;
    for (int i = 1; i <= s_len; i++)
        max *= i;

    ans = (char **)malloc(sizeof(char *) * max);
    dfs(s, s_len, 0, return_size);

    return ans;
}

//leetcode submit region end(Prohibit modification and deletion)
