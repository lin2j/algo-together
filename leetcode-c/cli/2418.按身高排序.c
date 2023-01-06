/*
 * @lc app=leetcode.cn id=2418 lang=c
 *
 * [2418] 按身高排序
 *
 * https://leetcode.cn/problems/sort-the-people/description/
 *
 * algorithms
 * Easy (78.25%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    11.2K
 * Total Submissions: 14.3K
 * Testcase Example:  '["Mary","John","Emma"]\n[180,165,170]'
 *
 * 给你一个字符串数组 names ，和一个由 互不相同 的正整数组成的数
 * 组 heights 。两个数组的长度均为 n 。
 * 
 * 对于每个下标 i，names[i] 和 heights[i] 表示第 i 个人的名字和身高。
 * 
 * 请按身高 降序 顺序返回对应的名字数组 names 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：names = ["Mary","John","Emma"], heights = [180,165,170]
 * 输出：["Mary","Emma","John"]
 * 解释：Mary 最高，接着是 Emma 和 John 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：names = ["Alice","Bob","Bob"], heights = [155,185,150]
 * 输出：["Bob","Alice","Bob"]
 * 解释：第一个 Bob 最高，然后是 Alice 和第二个 Bob 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == names.length == heights.length
 * 1 <= n <= 10^3
 * 1 <= names[i].length <= 20
 * 1 <= heights[i] <= 10^5
 * names[i] 由大小写英文字母组成
 * heights 中的所有值互不相同
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start

typedef struct {
        int height;
        char *name;
} pair;


static inline int pair_cmp(const void *a, const void *b)
{
        pair *aa = (pair *)a;
        pair *bb = (pair *)b;

        return bb->height - aa->height;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** sortPeople(char **names, int names_size,
                   int *heights, int heights_size,
                   int *return_size)
{
        pair *people = malloc(sizeof(pair) * names_size);
        for (int i = 0; i < names_size; i++) {
                pair p = {.height = heights[i], .name = names[i]};
                people[i] = p;
        }

        qsort(people, names_size, sizeof(pair), pair_cmp);

        *return_size = names_size;
        char **result = malloc(sizeof(char *) * names_size);
        for (int i = 0; i < names_size; i++)
                result[i] = people[i].name;

        free(people);

        return result;
}
// @lc code=end


