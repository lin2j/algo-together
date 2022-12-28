/*
 * @lc app=leetcode.cn id=506 lang=c
 *
 * [506] 相对名次
 *
 * https://leetcode.cn/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (65.14%)
 * Likes:    194
 * Dislikes: 0
 * Total Accepted:    72.6K
 * Total Submissions: 111.5K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 给你一个长度为 n 的整数数组 score ，其中 score[i] 是第 i 位运动员在比赛中的得分。所有得分都 互不相同 。
 * 
 * 运动员将根据得分 决定名次 ，其中名次第 1 的运动员得分最高，名次第 2 的运动员得分第 2
 * 高，依此类推。运动员的名次决定了他们的获奖情况：
 * 
 * 
 * 名次第 1 的运动员获金牌 "Gold Medal" 。
 * 名次第 2 的运动员获银牌 "Silver Medal" 。
 * 名次第 3 的运动员获铜牌 "Bronze Medal" 。
 * 从名次第 4 到第 n 的运动员，只能获得他们的名次编号（即，名次第 x 的运动员获得编号 "x"）。
 * 
 * 
 * 使用长度为 n 的数组 answer 返回获奖，其中 answer[i] 是第 i 位运动员的获奖情况。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：score = [5,4,3,2,1]
 * 输出：["Gold Medal","Silver Medal","Bronze Medal","4","5"]
 * 解释：名次为 [1^st, 2^nd, 3^rd, 4^th, 5^th] 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：score = [10,3,8,9,4]
 * 输出：["Gold Medal","5","Bronze Medal","Silver Medal","4"]
 * 解释：名次为 [1^st, 5^th, 3^rd, 2^nd, 4^th] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == score.length
 * 1 <= n <= 10^4
 * 0 <= score[i] <= 10^6
 * score 中的所有值 互不相同
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

// @lc code=start

char *str[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};

int cmp(const void *a, const void *b)
{
        int *aa = (int *)a;
        int *bb = (int *)b;
        return bb[0] - aa[0];
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 1. 创建一个二维数组 arr，第一行记录分数，第二行记录分数的原始索引
 * 2. 对二维数组进行排序，规则是按分数从高到低排序
 * 3. 创建一个字符串数组 res
 * 3. 遍历二维数组 arr，索引 i = 0，oi = arr[i][1] 则是名次对应的原始索引
 *  3.1 当 oi < 3，则将前三名分别单独设置固定字符串 res[oi] = str[i]
 *  3.2 当 oi >= 3，则其他的则是索引加上 res[oi] = i + 1
 *
 */
char ** findRelativeRanks(int *score, int score_size, int *return_size)
{
        int arr[score_size][2];

        for (int i = 0; i < score_size; i++) {
                arr[i][0] = score[i];
                arr[i][1] = i;
        }

        qsort(arr, score_size, sizeof(arr[0]), cmp);

        char **res = malloc(sizeof(char *) * score_size);
        for (int i = 0; i < score_size; i++) {
                int oi = arr[i][1];
                if (i < 3) {
                        res[oi] = str[i];
                        continue;
                }
                // 数组的最大长度是 
                // 10000，所以最小的名次是 10000
                res[oi] = malloc(sizeof(char) * 6);
                sprintf(res[oi], "%d", i + 1);
        }
        *return_size = score_size;
        return res;
}
// @lc code=end


