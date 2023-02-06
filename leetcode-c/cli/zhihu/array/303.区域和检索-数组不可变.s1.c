/*
 * @lc app=leetcode.cn id=303 lang=c
 *
 * [303] 区域和检索 - 数组不可变
 *
 * https://leetcode.cn/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (76.27%)
 * Likes:    529
 * Dislikes: 0
 * Total Accepted:    202.9K
 * Total Submissions: 266K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * 给定一个整数数组  nums，处理以下类型的多个查询:
 * 
 * 
 * 计算索引 left 和 right （包含 left 和 right）之间的 nums 元素的 和 ，
 * 其中 left <= right
 * 
 * 
 * 实现 NumArray 类：
 * 
 * 
 * NumArray(int[] nums) 使用数组 nums 初始化对象
 * int sumRange(int i, int j) 返回数组 nums 中索引 left 和 right 之间的元素的 总和 ，包含 left 和
 * right 两点（也就是 nums[left] + nums[left + 1] + ... + nums[right] )
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：
 * ["NumArray", "sumRange", "sumRange", "sumRange"]
 * [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
 * 输出：
 * [null, 1, -1, -3]
 * 
 * 解释：
 * NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
 * numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
 * numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
 * numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^5 <= nums[i] <= 10^5
 * 0 <= i <= j < nums.length
 * 最多调用 10^4 次 sumRange 方法
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start

/*
 * 前缀和
 * 可以在 nums[i] 保存为 [0, i] 的数组元素之和 
 * 这样计算 [i, j] 区间的元素之和时，只需计算 nums[j] - nums[i - 1]
 *
 */

typedef struct {
        int *sum_nums;
} NumArray;


NumArray* numArrayCreate(int *nums, int nums_size) 
{
        NumArray *obj = malloc(sizeof(NumArray));
        obj->sum_nums = malloc(sizeof(int) * (nums_size + 1));

        obj->sum_nums[0] = 0;
        for (int i = 0; i < nums_size; i++)
                obj->sum_nums[i + 1] = obj->sum_nums[i] + nums[i];

        return obj;
}

int numArraySumRange(NumArray *obj, int left, int right)
{
        return obj->sum_nums[right + 1] - obj->sum_nums[left];
}

void numArrayFree(NumArray* obj) {
        free(obj->sum_nums);
        free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
// @lc code=end


