/*
 * @lc app=leetcode.cn id=1710 lang=c
 *
 * [1710] 卡车上的最大单元数
 *
 * https://leetcode.cn/problems/maximum-units-on-a-truck/description/
 *
 * algorithms
 * Easy (73.62%)
 * Likes:    109
 * Dislikes: 0
 * Total Accepted:    47.3K
 * Total Submissions: 64.3K
 * Testcase Example:  '[[1,3],[2,2],[3,1]]\n4'
 *
 * 请你将一些箱子装在 一辆卡车 上。给你一个二维数组 boxTypes ，
 * 其中 boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi] ：
 * 
 * 
 * numberOfBoxesi 是类型 i 的箱子的数量。
 * numberOfUnitsPerBoxi 是类型 i 每个箱子可以装载的单元数量。
 * 
 * 
 * 整数 truckSize 表示卡车上可以装载 箱子 的 最大数量 。
 * 只要箱子数量不超过 truckSize ，你就可以选择任意箱子装到卡车上。
 * 
 * 返回卡车可以装载 单元 的 最大 总数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
 * 输出：8
 * 解释：箱子的情况如下：
 * - 1 个第一类的箱子，里面含 3 个单元。
 * - 2 个第二类的箱子，每个里面含 2 个单元。
 * - 3 个第三类的箱子，每个里面含 1 个单元。
 * 可以选择第一类和第二类的所有箱子，以及第三类的一个箱子。
 * 单元总数 = (1 * 3) + (2 * 2) + (1 * 1) = 8
 * 
 * 示例 2：
 * 
 * 
 * 输入：boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
 * 输出：91
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 i, numberOfUnitsPerBoxi 
 * 1 
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start

static inline int cmp(const void *a, const void *b)
{
        int *aa = *(int **)a;
        int *bb = *(int **)b;
        return bb[1] - aa[1];
}

/*
 * 对于卡车来讲，装的箱子数是固定的，因此箱子能装的单元数越多
 * 优先级越高
 */
int maximumUnits(int **box_types, int box_types_size,
                 int *box_types_col_size, int truck_size)
{
        qsort(box_types, box_types_size, sizeof(int *), cmp);

        int result = 0;
        for (int i = 0; i < box_types_size && truck_size > 0; i++) {
                int box_nums = box_types[i][0];
                int c = truck_size > box_nums ? box_nums : truck_size;
                result += c * box_types[i][1];
                truck_size -= c;
        }
        return result;

}
// @lc code=end


