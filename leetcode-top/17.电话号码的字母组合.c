/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (59.85%)
 * Total Accepted:    907.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

#include <stdlib.h>
#include <string.h>


// @lc code=start

char btns[11][5] = {
        "\0", 
        "\0",   "abc", "def", 
        "ghi",  "jkl", "mno", 
        "pqrs", "tuv", "wxyz"
};

static void find_combination(char *digits, char *tmp, int t_size,
                             char **ans, int *ret_size)
{
        if (*digits == '\0') {
                tmp[t_size] = '\0';
                ans[*ret_size] = malloc(sizeof(char) * 5);
                memcpy(ans[*ret_size], tmp, 5);
                (*ret_size)++;
                return;
        }
        
        for (char *btn = btns[*digits - '0']; *btn != '\0'; btn++) {
                tmp[t_size] = *btn;
                find_combination(digits + 1, tmp, t_size + 1, ans, ret_size);
        }
}


/**
 * 回溯
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char *digits, int *ret_size)
{
        *ret_size = 0;
        int len = strlen(digits);
        if (len == 0) return NULL;

        int ans_len = 1;
        for (int i = 0; i < len; i++) {
                ans_len *= 4;
        }

        char tmp[5] = {0};
        char **ans = malloc(sizeof(char *) * ans_len);
        find_combination(digits, tmp, 0, ans, ret_size);

        return ans;
}

// @lc code=end

