/*
 * @lc app=leetcode.cn id=119 lang=c
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode.cn/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (68.88%)
 * Likes:    449
 * Dislikes: 0
 * Total Accepted:    246.9K
 * Total Submissions: 358.2K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
 * 
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: rowIndex = 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: rowIndex = 0
 * 输出: [1]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: rowIndex = 1
 * 输出: [1,1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 0 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？
 * 
 */
#include <stdlib.h>
#include <string.h>

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 杨辉三角的第 i 行只与 i-1 行相关，因此只要用两个数组就可以模拟整个过程
 *
 * 可以利用滚动数组的思想
 */
int * getRow(int row_index, int *return_size)
{
        *return_size = row_index + 1;

        int *pre = malloc(sizeof(int) * (*return_size));
        int *cur = malloc(sizeof(int) * (*return_size));
        
        memset(pre, 0, sizeof(int) * (*return_size));
        memset(cur, 0, sizeof(int) * (*return_size));

        for (int i = 0; i <= row_index; i++) {
                cur[0] = cur[i] = 1;
                for (int j = 1; j < i; j++)
                        cur[j] = pre[j-1] + pre[j];

                int *tmp = pre;
                pre = cur;
                cur = tmp;
        }
        return pre;
}
// @lc code=end


