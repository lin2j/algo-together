//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。 
//
// 
//
// 示例 1： 
//
// 输入：head = [1,3,2]
//输出：[2,3,1] 
//
// 
//
// 限制： 
//
// 0 <= 链表长度 <= 10000 
// Related Topics 栈 递归 链表 双指针 👍 319 👎 0

struct ListNode {
    int val;
    struct ListNode *next;
};


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode *head, int *return_size){
	int list_len = 0;
	struct ListNode *tmp = head;
	while(tmp != NULL) {
		tmp = tmp->next;
		list_len++;
	}

	if (list_len == 0) {
		*return_size = 0;
		return NULL;
	}

	int *ans = (int *)malloc(sizeof(int) * list_len);
	*return_size = list_len;
	int *p = ans + (list_len - 1);
	while(head != NULL) {
		*p-- = head->val;
		head = head->next;
	}

	return ans;
}
//leetcode submit region end(Prohibit modification and deletion)
