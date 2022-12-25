//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。 
//
// 示例1： 
//
// 输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4 
//
// 限制： 
//
// 0 <= 链表长度 <= 1000 
//
// 注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/ 
// Related Topics 递归 链表 👍 264 👎 0

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


struct ListNode* mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	struct ListNode *dum = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *cur = dum;

	while(l1 != NULL && l2 != NULL) {
		if (l1->val <= l2->val) {
			cur->next = l1;
			l1 = l1->next;
		} else {
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}

	cur->next = l1 != NULL ? l1 : l2;

	cur = dum->next;
	free(dum);

	return cur;
}

//leetcode submit region end(Prohibit modification and deletion)
