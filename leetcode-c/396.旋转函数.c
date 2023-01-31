/*
 * @lc app=leetcode.cn id=396 lang=c
 *
 * [396] 旋转函数
 *
 * https://leetcode.cn/problems/rotate-function/description/
 *
 * algorithms
 * Medium (53.79%)
 * Likes:    250
 * Dislikes: 0
 * Total Accepted:    47.1K
 * Total Submissions: 87.6K
 * Testcase Example:  '[4,3,2,6]'
 *
 * 给定一个长度为 n 的整数数组 nums 。
 * 
 * 假设 arrk 是数组 nums 顺时针旋转 k 个位置后的数组，我们定义 nums 的 旋转函数  F 为：
 * 
 * 
 * F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]
 * 
 * 
 * 返回 F(0), F(1), ..., F(n-1)中的最大值 。
 * 
 * 生成的测试用例让答案符合 32 位 整数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [4,3,2,6]
 * 输出: 26
 * 解释:
 * F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
 * F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
 * F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
 * F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
 * 所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [100]
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^5
 * -100 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/*
 * 记数组的元素之和为 numSum。根据公式可以得到
 * F(0) = 0 * nums[0] + 1 * nums[1] + ... + (n - 1) * nums[n-1]
 * F(1) = 1 * nums[0] + 2 * nums[1] + ... + 0 * nums[n-1]
 * 
 * F(1) - F(0) = nums[0] + nums[1] + ... + nums[n-1] - n * nums[n-1]
 * F(1) = F(0) + numsSum - n * nums[n-1]
 *
 * 
 * 对于 1 ≤ k ≤ n，有
 *
 * F(k) = F(k-1) + numSum - n * nums[n - k]
 *
 * T(n): O(n)
 * S(n): O(1)
 */
int maxRotateFunction(int *nums, int n)
{
        int f = 0, sum = 0;
        for (int i = 0; i < n; i++) {
                f += i * nums[i];
                sum += nums[i];
        }

        int ans = f;
        for (int i = n - 1; i > 0; i--) {
                f = f + sum - n * nums[i];
                ans = MAX(f, ans);
        }

        return ans;
}
// @lc code=end


