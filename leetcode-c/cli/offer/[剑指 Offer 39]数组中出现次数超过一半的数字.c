//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。 
//
// 
//
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。 
//
// 
//
// 示例 1: 
//
// 输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
//输出: 2 
//
// 
//
// 限制： 
//
// 1 <= 数组长度 <= 50000 
//
// 
//
// 注意：本题与主站 169 题相同：https://leetcode-cn.com/problems/majority-element/ 
//
// 
//
// Related Topics 数组 哈希表 分治 计数 排序 👍 308 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


int majorityElement(int *nums, int nums_size)
{
        int candidate = nums[0];
        int candidate_count = 1;
        for (int i = 1; i < nums_size; i++) {
                if (candidate_count == 0) {
                        candidate = nums[i];
                        candidate_count = 1;
                        continue;
                }
                int r = nums[i] == candidate ? 1 : -1;
                candidate_count += r;
        }
        return candidate;
}

//leetcode submit region end(Prohibit modification and deletion)
