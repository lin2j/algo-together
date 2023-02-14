/*
 * @lc app=leetcode.cn id=553 lang=c
 *
 * [553] 最优除法
 *
 * https://leetcode.cn/problems/optimal-division/description/
 *
 * algorithms
 * Medium (64.85%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    30.9K
 * Total Submissions: 47.7K
 * Testcase Example:  '[1000,100,10,2]'
 *
 * 给定一正整数数组 nums，nums 中的相邻整数将进行浮点除法。
 * 例如， [2,3,4] -> 2 / 3 / 4 。
 * 
 * 
 * 例如，nums = [2,3,4]，我们将求表达式的值 "2/3/4"。
 * 
 * 
 * 但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。
 * 你需要找出怎么添加括号，以便计算后的表达式的值为最大值。
 * 
 * 以字符串格式返回具有最大值的对应表达式。
 * 
 * 注意：你的表达式不应该包含多余的括号。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: [1000,100,10,2]
 * 输出: "1000/(100/10/2)"
 * 解释: 1000/(100/10/2) = 1000/((100/10)/2) = 200
 * 但是，以下加粗的括号 "1000/((100/10)/2)" 是冗余的，
 * 因为他们并不影响操作的优先级，所以你需要返回 "1000/(100/10/2)"。
 * 
 * 其他用例:
 * 1000/(100/10)/2 = 50
 * 1000/(100/(10/2)) = 50
 * 1000/100/10/2 = 0.5
 * 1000/100/(10/2) = 2
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [2,3,4]
 * 输出: "2/(3/4)"
 * 解释: (2/(3/4)) = 8/3 = 2.667
 * 可以看出，在尝试了所有的可能性之后，我们无法得到一个结果大于 2.667 的表达式。
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 1 <= nums.length <= 10
 * 2 <= nums[i] <= 1000
 * 对于给定的输入只有一种最优除法。
 * 
 * 
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// @lc code=start

#define MAX_STR_LEN 64

char * optimalDivision(int* nums, int nums_size)
{
        char *res = malloc(sizeof(char) * MAX_STR_LEN);

        if (nums_size == 1) {
                sprintf(res, "%d", nums[0]);
                return res;
        }

        if (nums_size == 2) {
                sprintf(res, "%d/%d", nums[0], nums[1]);
                return res;
        }

        sprintf(res, "%d/(%d", nums[0], nums[1]);
        char str[5];
        int pos = strlen(res);
        for (int i = 2; i < nums_size; i++) {
                sprintf(str, "%d", nums[i]);
                sprintf(res + pos, "/%s", str);
                pos += strlen(str) + 1;
        }
        sprintf(res + pos, "%s", ")");

        return res;
}
// @lc code=end


