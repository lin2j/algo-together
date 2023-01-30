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


int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = malloc(sizeof(int) * (*returnSize));
    row[0] = 1;
    for (int i = 1; i <= rowIndex; ++i) {
        row[i] = 1LL * row[i - 1] * (rowIndex - i + 1) / i;
    }
    return row;
}

// @lc code=end


