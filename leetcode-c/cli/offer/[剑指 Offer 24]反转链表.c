//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。 
//
// 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 206 题相同：https://leetcode-cn.com/problems/reverse-linked-list/ 
// Related Topics 递归 链表 👍 460 👎 0


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


struct ListNode *reverseList(struct ListNode *head)
{
	struct ListNode *cur = head, *prev = NULL;

	while(cur != NULL) {
		struct ListNode *next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;
}

//leetcode submit region end(Prohibit modification and deletion)
