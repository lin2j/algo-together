/*
 * @lc app=leetcode.cn id=LCP18 lang=c
 *
 * [LCP 18] 早餐组合
 *
 * https://leetcode.cn/problems/2vYnGI/description/
 *
 * algorithms
 * Easy (30.01%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    23.7K
 * Total Submissions: 78.9K
 * Testcase Example:  '[10,20,5]\n[5,5,2]\n15'
 *
 * 小扣在秋日市集选择了一家早餐摊位，一维整型数组 `staple` 中记录了每种
 * 主食的价格，一维整型数组 `drinks` 中记录了每种饮料的价格。小扣的计划
 * 选择一份主食和一款饮料，且花费不超过 `x` 元。
 *
 * 请返回小扣共有多少种购买方案。
 * 
 * 注意：答案需要以 `1e9 + 7 (1000000007)` 为底取模，如：计算初始结果
 * 为：`1000000008`，请返回 `1`
 * 
 * **示例 1：**
 * >输入：`staple = [10,20,5], drinks = [5,5,2], x = 15`
 * >
 * >输出：`6`
 * >
 * >解释：小扣有 6 种购买方案，所选主食与所选饮料在数组中对应的下标分别是：
 * >第 1 种方案：staple[0] + drinks[0] = 10 + 5 = 15；
 * >第 2 种方案：staple[0] + drinks[1] = 10 + 5 = 15；
 * >第 3 种方案：staple[0] + drinks[2] = 10 + 2 = 12；
 * >第 4 种方案：staple[2] + drinks[0] = 5 + 5 = 10；
 * >第 5 种方案：staple[2] + drinks[1] = 5 + 5 = 10；
 * >第 6 种方案：staple[2] + drinks[2] = 5 + 2 = 7。
 * 
 * **示例 2：**
 * >输入：`staple = [2,1,1], drinks = [8,9,5,1], x = 9`
 * >
 * >输出：`8`
 * >
 * >解释：小扣有 8 种购买方案，所选主食与所选饮料在数组中对应的下标分别是：
 * >第 1 种方案：staple[0] + drinks[2] = 2 + 5 = 7；
 * >第 2 种方案：staple[0] + drinks[3] = 2 + 1 = 3；
 * >第 3 种方案：staple[1] + drinks[0] = 1 + 8 = 9；
 * >第 4 种方案：staple[1] + drinks[2] = 1 + 5 = 6；
 * >第 5 种方案：staple[1] + drinks[3] = 1 + 1 = 2；
 * >第 6 种方案：staple[2] + drinks[0] = 1 + 8 = 9；
 * >第 7 种方案：staple[2] + drinks[2] = 1 + 5 = 6；
 * >第 8 种方案：staple[2] + drinks[3] = 1 + 1 = 2；
 * 
 * **提示：**
 * + `1 
 */
#include <stdlib.h>

// @lc code=start
#define MOD 1000000007

static inline int int_cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}


int breakfastNumber(int *staple, int staple_size,
                    int *drinks, int drinks_size, int x){
        qsort(staple, staple_size, sizeof(int), int_cmp);
        qsort(drinks, drinks_size, sizeof(int), int_cmp);

        for (int i = 0; i < staple_size; i++)
                if (staple[i] >= x) {
                        staple_size = i + 1;
                        break;
                }

        for (int i = 0; i < drinks_size; i++)
                if (drinks[i] >= x) {
                        drinks[i] = i + 1;
                        break;
                }

        int ans = 0;
        for (int i = 0; i < staple_size; i++) {
                int d = x - staple[i];
                for (int j = drinks_size - 1; j >= 0; j--)
                        if (drinks[j] <= d) {
                                ans = j + 1;
                                ans = ans % MOD;
                        }
        }

        return ans;
}

// @lc code=end


