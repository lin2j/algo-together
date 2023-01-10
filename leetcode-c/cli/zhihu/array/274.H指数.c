/*
 * @lc app=leetcode.cn id=274 lang=c
 *
 * [274] H 指数
 *
 * https://leetcode.cn/problems/h-index/description/
 *
 * algorithms
 * Medium (44.47%)
 * Likes:    292
 * Dislikes: 0
 * Total Accepted:    71.8K
 * Total Submissions: 161.3K
 * Testcase Example:  '[3,0,6,1,5]'
 *
 * 给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引
 * 用的次数。计算并返回该研究者的 h 指数。
 * 
 * 根据维基百科上 h 指数的定义：h 代表“高引用次数”，一名科研人员的 h指数是指
 * 他（她）的 （n 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。且其余的 
 * n - h 篇论文每篇被引用次数 不超过 h 次。
 * 
 * 如果 h 有多种可能的值，h 指数 是其中最大的那个。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：citations = [3,0,6,1,5]
 * 输出：3 
 * 解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
 * 由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3。
 * 
 * 示例 2：
 * 
 * 
 * 输入：citations = [1,3,1]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == citations.length
 * 1 <= n <= 5000
 * 0 <= citations[i] <= 1000
 * 
 * 
 */
#include <stdint.h>
#include <stdlib.h>

// @lc code=start
static inline int int_cmp_rev(const void *a, const void *b)
{
        return *(int *)b - *(int *)a;
}

/*
 * h：数组中有 h 个数大于等于 h
 *
 * 1. 将数组从大到小排序
 * 2. 遍历数组，如果元素大于 h 则，h++
 * 3. 最终答案为 h
 */
int hIndex(int* citations, int citations_size)
{
        qsort(citations, citations_size, sizeof(int), int_cmp_rev);

        int h = 0;
        for(int i = 0; i < citations_size; i++)
                if (h < citations[i])
                        h++;

        return h;
}
// @lc code=end


