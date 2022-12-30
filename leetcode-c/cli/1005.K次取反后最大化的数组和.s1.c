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

#define RANGE_MIN -100
#define RANGE_MAX 100
#define OFFSET 100

#define MIN(a, b) (a) > (b) ? (b) : (a)

/*
 * 如果要使得取反 k 次之后的和最大，那么应该将数字从小到大排序之后，
 * 优先取反最小的负数，之后再取反整体数字之中的最小数
 * 假设总个数为 n，负数为 m (1 <= m <= n)
 * 1. 如果 k <= m，那么只要尽量将负数取反为即可
 * 2. 如果 k > m，则在将所有的负数取反之后，剩下的 c = (k - m) 次取反
 *   2.1 如果 c 为偶数，则最终取反的结果会抵消掉
 *   2.2 如果 c 为奇数，则还需要取反一次，这次取反应当用在当前数组的最小数身上
 *
 * 但是注意到数组的元素范围在 [-100, 100]，因此可以使用哈希表或者计数数组将
 * 元素的个数保存起来，直接统计 [-100, 100] 之间每个元素出现的次数，采用升序
 * 遍历，可以省去排序的过程
 */
int largestSumAfterKNegations(int *nums, int nums_size, int k)
{
        // 计数数组
        int count_map[201] = {0};
        int sum = 0;

        for (int i = 0; i < nums_size; i++) {
                count_map[nums[i] + OFFSET]++;
                sum += nums[i];
        }

        for (int i = RANGE_MIN; i < 0; i++) {
                int ops = MIN(k, count_map[i + OFFSET]);
                if (ops == 0) continue;

                sum += -i * ops * 2;
                count_map[i + OFFSET] = count_map[i + OFFSET] - ops;
                count_map[-i + OFFSET] = count_map[-i + OFFSET] + ops;

                k -= ops;
                if (k == 0) break;
        }

        if (k > 0 && (k & 1) == 1 && count_map[0 + OFFSET] == 0) {
                for (int i = 1; i <= RANGE_MAX; i++) {
                        if (count_map[i + OFFSET] > 0) {
                                sum -= i * 2;
                                break;
                        }
                }
        }

        return sum;
}
// @lc code=end


