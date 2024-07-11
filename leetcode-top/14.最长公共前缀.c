/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 *
 * https://leetcode.cn/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (44.10%)
 * Total Accepted:    1.3M
 * Total Submissions: 3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 仅由小写英文字母组成
 * 
 * 
 */

#include <string.h>
#include <stdlib.h>


// @lc code=start

static int sort_cmp(const void *a, const void *b)
{
        return strcmp(*(const char **) a, *(const char **) b);
}

char * longestCommonPrefix(char **strs, int s_size) 
{
        if (s_size == 0) return NULL;
        if (s_size == 1) return strs[0];
 
        qsort(strs, s_size, sizeof(const char *), sort_cmp);
    
        char *a = strs[0];
        char *b = strs[s_size - 1];

        int i = 0;
        while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i]) i++;
        if (i == 0) return "";

        char *ans = malloc(sizeof(char) * i + 1);
        int k = 0, j = 0;
        while (j < i) ans[k++] = a[j++];
        ans[k] = '\0';

        return ans;
}

// @lc code=end

