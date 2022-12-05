//找出数组中重复的数字。 
//
// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
//请找出数组中任意一个重复的数字。 
//
// 示例 1： 
//
// 输入：
//[2, 3, 1, 0, 2, 5, 3]
//输出：2 或 3 
// 
//
// 
//
// 限制： 
//
// 2 <= n <= 100000 
//
// Related Topics 数组 哈希表 排序 👍 1016 👎 0

package leetcode.editor.cn;

/**
 * <<剑指 Offer 03>> 数组中重复的数字
 *
 * @author lin2j linjinjia047@163.com
 * @date 2022-12-05 21:23:47
 */
public class ShuZuZhongZhongFuDeShuZiLcof {
    public static void main(String[] args) {
        Solution solution = new ShuZuZhongZhongFuDeShuZiLcof().new Solution();
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public int findRepeatNumber(int[] nums) {
            // 遍历 nums 在遇到不重复的数字时，将 nums[i] 移到索引为 nums[i] 的地方
            // 如果 nums[i] == i，说明 nums[i] 已经在正确的位置上，不用移动
            // 如果 nums[i] 位置上的数字已经是 nums[i]，说明 nums[i] 是重复的
            // 需要注意当遍历到 i 位置时，要一直等到 nums[i] 放到 i 上才能遍历到下一位
            for (int i = 0; i < nums.length; ) {
                if (nums[i] == i) {
                    i++;
                    continue;
                }
                int idx = nums[i];
                if (nums[i] == nums[idx]) {
                    return nums[i];
                }
                swap(nums, i, idx);
            }
            return -1;
        }

        private void swap(int[] nums, int i, int j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}

