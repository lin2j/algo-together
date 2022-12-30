/*
 * @lc app=leetcode.cn id=1005 lang=c
 *
 * [1005] K 次取反后最大化的数组和
 *
 * https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/
 *
 * algorithms
 * Easy (51.26%)
 * Likes:    303
 * Dislikes: 0
 * Total Accepted:    108.9K
 * Total Submissions: 212.4K
 * Testcase Example:  '[4,2,3]\n1'
 *
 * 给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
 * 
 * 
 * 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
 * 
 * 
 * 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
 * 
 * 以这种方式修改数组后，返回数组 可能的最大和 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,2,3], k = 1
 * 输出：5
 * 解释：选择下标 1 ，nums 变为 [4,-2,3] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,-1,0,2], k = 3
 * 输出：6
 * 解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [2,-3,-1,5,-4], k = 2
 * 输出：13
 * 解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -100 <= nums[i] <= 100
 * 1 <= k <= 10^4
 * 
 * 
 */

#include <stdint.h>
#include <stdlib.h>

// @lc code=start

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/*
 * 如果要使得取反 k 次之后的和最大，那么应该将数字从小到大排序之后，
 * 优先取反最小的负数，之后再取反整体数字之中的最小数
 * 假设总个数为 n，负数为 m (1 <= m <= n)
 * 1. 如果 k <= m，那么只要尽量将负数取反为即可
 * 2. 如果 k > m，则在将所有的负数取反之后，剩下的 c = (k - m) 次取反
 *   2.1 如果 c 为偶数，则最终取反的结果会抵消掉
 *   2.2 如果 c 为奇数，则还需要取反一次，这次取反应当用在当前数组的最小数身上
 */
int largestSumAfterKNegations(int *nums, int nums_size, int k)
{
        qsort(nums, nums_size, sizeof(int), cmp);

        int sum = 0;
        int min = INT32_MAX;
        for (int i = 0; i < nums_size; i++) {
                if (nums[i] < 0 && k > 0) {
                        nums[i] = -nums[i];
                        k--;
                }
                sum += nums[i];
                if (nums[i] < min) {
                        min = nums[i];
                }
        }

        if ((k & 1) == 1) {
                // 最小数在之前计算总和时已经算入
                // 因此这里要减去两倍
                sum += -min * 2;
        }
        
        return sum;
}
// @lc code=end


