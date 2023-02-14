/*
 * @lc app=leetcode.cn id=539 lang=c
 *
 * [539] 最小时间差
 *
 * https://leetcode.cn/problems/minimum-time-difference/description/
 *
 * algorithms
 * Medium (66.11%)
 * Likes:    231
 * Dislikes: 0
 * Total Accepted:    60.7K
 * Total Submissions: 91.9K
 * Testcase Example:  '["23:59","00:00"]'
 *
 * 给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个
 * 时间的最小时间差并以分钟数表示。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：timePoints = ["23:59","00:00"]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：timePoints = ["00:00","23:59","00:00"]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= timePoints.length <= 2 * 10^4
 * timePoints[i] 格式为 "HH:MM"
 * 
 * 
 */
#include <stdlib.h>
#include <string.h>

// @lc code=start

#define MIN(a, b) ((a) < (b) ? (a) : (b))

static inline int cmp_str(const void *a, const void *b)
{
        return strcmp(*(char **)a, *(char **)b);
}

static int get_minutes(char *t)
{
        int hours = (t[0] - '0') * 10 + t[1] - '0';
        int minutes = (t[3] - '0') * 10 + t[4] - '0';
        return hours * 60 + minutes;
}

int findMinDifference(char **time_points, int time_points_size)
{
        // 根据题意，一共有 24×60=1440 种不同的时间。
        // 由鸽巢原理可知，如果 timePoints 的长度超过
        // 1440，那么必然会有两个相同的时间，此时可以
        // 直接返回 0。
        if (time_points_size > 1440)
                return 0;


        qsort(time_points, time_points_size, sizeof(char *), cmp_str);

        int ans = 1440;

        int t0_minutes = get_minutes(time_points[0]);
        int pre_minutes = t0_minutes;
        for (int i = 1; i < time_points_size; i++) {
                int minutes = get_minutes(time_points[i]);
                ans = MIN(ans, minutes - pre_minutes);
                pre_minutes = minutes;
        }

        // 计算首尾时间差
        ans = MIN(ans, t0_minutes + 1440 - pre_minutes);

        return ans;
}
// @lc code=end


