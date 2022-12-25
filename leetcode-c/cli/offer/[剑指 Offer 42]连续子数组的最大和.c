//输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。 
//
// 要求时间复杂度为O(n)。 
//
// 
//
// 示例1: 
//
// 输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 10^5 
// -100 <= arr[i] <= 100 
// 
//
// 注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/ 
//
// 
//
// Related Topics 数组 分治 动态规划 👍 587 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


int maxSubArray(int* nums, int nums_size)
{
        // min of int, -2^(31)
        int ans = 0x80000000;
        int cur_sum = 0;

        for (int i = 0; i < nums_size; ++i) {
                if (cur_sum < 0) {
                        // if cur_sum < 0, then cur_sum + nums[i] < nums[i]
                        // so the best choice is cur_sum = nums[i]
                        cur_sum = nums[i];
                } else {
                        cur_sum += nums[i];
                }

                ans = ans > cur_sum ? ans : cur_sum;
        }

        return ans;
}

//leetcode submit region end(Prohibit modification and deletion)
