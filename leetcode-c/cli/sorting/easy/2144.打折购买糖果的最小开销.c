/*
 * @lc app=leetcode.cn id=2144 lang=c
 *
 * [2144] 打折购买糖果的最小开销
 *
 * https://leetcode.cn/problems/minimum-cost-of-buying-candies-with-discount/description/
 *
 * algorithms
 * Easy (67.41%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    9K
 * Total Submissions: 13.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 一家商店正在打折销售糖果。每购买 两个 糖果，商店会 免费 送一个糖果。
 * 
 * 免费送的糖果唯一的限制是：它的价格需要小于等于购买的两个糖果价格的 较小值 。
 * 
 * 
 * 比方说，总共有 4 个糖果，价格分别为 1 ，2 ，3 和 4 ，一位顾客买了价格为 
 * 2 和 3 的糖果，那么他可以免费获得价格为 1 的糖果，但不能获得价格为 4 的糖果。
 * 
 * 
 * 给你一个下标从 0 开始的整数数组 cost ，其中 cost[i] 表示第 i 个糖果的价格，
 * 请你返回获得 所有 糖果的 最小 总开销。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：cost = [1,2,3]
 * 输出：5
 * 解释：我们购买价格为 2 和 3 的糖果，然后免费获得价格为 1 的糖果。
 * 总开销为 2 + 3 = 5 。这是开销最小的 唯一 方案。
 * 注意，我们不能购买价格为 1 和 3 的糖果，并免费获得价格为 2 的糖果。
 * 这是因为免费糖果的价格必须小于等于购买的 2 个糖果价格的较小值。
 * 
 * 
 * 示例 2：
 * 
 * 输入：cost = [6,5,7,9,2,2]
 * 输出：23
 * 解释：最小总开销购买糖果方案为：
 * - 购买价格为 9 和 7 的糖果
 * - 免费获得价格为 6 的糖果
 * - 购买价格为 5 和 2 的糖果
 * - 免费获得价格为 2 的最后一个糖果
 * 因此，最小总开销为 9 + 7 + 5 + 2 = 23 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：cost = [5,5]
 * 输出：10
 * 解释：由于只有 2 个糖果，我们需要将它们都购买，而且没有免费糖果。
 * 所以总最小开销为 5 + 5 = 10 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= cost.length <= 100
 * 1 <= cost[i] <= 100
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start


static inline int cmp(const void *a, const void *b)
{
        return *(int *)b - *(int *)a;
}

/*
 * 将数组从大到小进行排序，则有每买两个糖果 a,b，则第三个糖果 c 是可以赠送的，
 * 因为 a >= b >= c，且这个 c 除 a、b 之外不小于其他数的，所以买 a、b 送 c 是
 * 最优的。
 *
 * 除去 a、b、c，余下的糖果也可以使用该规则
 *
 * T(n): O(nlogn)
 * S(n): O(logn)
 */
int minimumCost(int *cost, int cost_size)
{
        qsort(cost, cost_size, sizeof(int), cmp);

        int ans = 0;
        for (int i = 0; i < cost_size; i++) {
                if (i % 3 == 2) continue;
                ans += cost[i];
        }
        
        return ans;
}
// @lc code=end


