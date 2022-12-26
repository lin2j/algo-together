/*
 * @lc app=leetcode.cn id=217 lang=c
 *
 * [217] 存在重复元素
 *
 * https://leetcode.cn/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (55.67%)
 * Likes:    871
 * Dislikes: 0
 * Total Accepted:    705.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,1]'
 *
 * 给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,1]
 * 输出：true
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：false
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,1,1,3,3,4,3,2,4,2]
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// @lc code=start


static int randomIndex(int l, int r) {
        srand(time(NULL));
        return rand() % (r - l) + l;
}


static void swap(int *nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
}

static int partition(int *nums, int l, int r) {
        if (l > r) {
                return -1;
        } 

        // ac 的关键，不然有些测试用例会超时
        int i = randomIndex(l, r);
        swap(nums, i, l);

        int v = nums[l];
        while(l < r) {
                while(l < r && nums[r] >= v) r--;
                swap(nums, l, r);
                while(l < r && nums[l] <= v) l++;
                swap(nums, l, r);
        }
        return l;
}

static void quick_sort(int *nums, int l, int r) {
        if (l >= r) {
                return;
        }
        int p = partition(nums, l, r);
        if (p == -1) {
                return;
        }
        quick_sort(nums, l, p - 1);
        quick_sort(nums, p + 1, r);
}

/*
 * 先将数组进行排序，然后在遍历排序后的数组，
 * 如果前后两个元素相同的话，则表示出现重复数字
 */
bool containsDuplicate(int *nums, int nums_size){
        quick_sort(nums, 0, nums_size - 1);

        for (int i = 1; i < nums_size; i++) {
                if (nums[i] == nums[i - 1]) {
                        return true;
                }
        }
        return false;
}
// @lc code=end

