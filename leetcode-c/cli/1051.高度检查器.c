/*
 * @lc app=leetcode.cn id=1051 lang=c
 *
 * [1051] 高度检查器
 *
 * https://leetcode.cn/problems/height-checker/description/
 *
 * algorithms
 * Easy (80.11%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    66.3K
 * Total Submissions: 82.7K
 * Testcase Example:  '[1,1,4,2,1,3]'
 *
 * 学校打算为全体学生拍一张年度纪念照。根据要求，学生需要按照 非递减 的高度
 * 顺序排成一行。
 * 
 * 排序后的高度情况用整数数组 expected 表示，其中 expected[i] 是预计排在这一
 * 行中第 i 位的学生的高度（下标从 0 开始）。
 * 
 * 给你一个整数数组 heights ，表示 当前学生站位 的高度情况。heights[i] 是这
 * 一行中第 i 位学生的高度（下标从 0 开始）。
 * 
 * 返回满足 heights[i] != expected[i] 的 下标数量 。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：heights = [1,1,4,2,1,3]
 * 输出：3 
 * 解释：
 * 高度：[1,1,4,2,1,3]
 * 预期：[1,1,1,2,3,4]
 * 下标 2 、4 、5 处的学生高度不匹配。
 * 
 * 示例 2：
 * 
 * 
 * 输入：heights = [5,1,2,3,4]
 * 输出：5
 * 解释：
 * 高度：[5,1,2,3,4]
 * 预期：[1,2,3,4,5]
 * 所有下标的对应学生高度都不匹配。
 * 
 * 示例 3：
 * 
 * 
 * 输入：heights = [1,2,3,4,5]
 * 输出：0
 * 解释：
 * 高度：[1,2,3,4,5]
 * 预期：[1,2,3,4,5]
 * 所有下标的对应学生高度都匹配。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= heights.length <= 100
 * 1 <= heights[i] <= 100
 * 
 * 
 */
#include <stdlib.h>
#include <string.h>
// @lc code=start

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}


/*
 * 1. 创建一个数组 excepted，内容为排序过后的高度
 * 2. 同时遍历 excepted 和 heights，统计统一索引下不相等的个数
 */
int heightChecker(int *heights, int heights_size)
{
        int *excepted = malloc(sizeof(int) * heights_size);
        memcpy(excepted, heights, sizeof(int) * heights_size);

        qsort(excepted, heights_size, sizeof(int), cmp);

        int ans = 0;
        
        for (int i = 0; i < heights_size; i++)
                if (heights[i] != excepted[i])
                        ans++;

        free(excepted);

        return ans;
}
// @lc code=end


