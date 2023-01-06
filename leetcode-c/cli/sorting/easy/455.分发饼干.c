/*
 * @lc app=leetcode.cn id=455 lang=c
 *
 * [455] 分发饼干
 *
 * https://leetcode.cn/problems/assign-cookies/description/
 *
 * algorithms
 * Easy (56.80%)
 * Likes:    624
 * Dislikes: 0
 * Total Accepted:    276.3K
 * Total Submissions: 486.4K
 * Testcase Example:  '[1,2,3]\n[1,1]'
 *
 * 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
 * 
 * 对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >=
 * g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: g = [1,2,3], s = [1,1]
 * 输出: 1
 * 解释: 
 * 你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
 * 虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
 * 所以你应该输出1。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: g = [1,2], s = [1,2,3]
 * 输出: 2
 * 解释: 
 * 你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
 * 你拥有的饼干数量和尺寸都足以让所有孩子满足。
 * 所以你应该输出2.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 1 
 * 
 * 
 */

#include <stdlib.h>

// @lc code=start

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/**
 * 将 g 和 s 递增排序
 *
 * 同时遍历 g 和 s, i,j 分别从 0 开始，count 表示得到满足的孩子的最大数量
 * 1. 如果 g[i] > s[j] 则说明 s[j] 不能满足 g[i]，则 j++
 * 2. 如果 g[i] <= s[j] 则说明 s[j] 是能够满足时 g[i] 的最小尺寸，count++
 *
 * 遍历结束，返回 count
 */
int findContentChildren(int *g, int size_g, 
                        int *s, int size_s)
{
        qsort(g, size_g, sizeof(int), cmp);
        qsort(s, size_s, sizeof(int), cmp);

        int n = size_g, m = size_s;
        int count = 0;
        for (int i = 0, j = 0; i < n && j < m; i++, j++) {
                while(j < m && g[i] > s[j]) j++;
                if (j < m) count++;
        }
        return count;
}
// @lc code=end


