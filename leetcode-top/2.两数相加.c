/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 *
 * https://leetcode.cn/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (43.81%)
 * Total Accepted:    2.1M
 * Total Submissions: 4.8M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 <= Node.val <= 9
 * 题目数据保证列表表示的数字不含前导零
 * 
 * 
 */

#include <stdlib.h>

 struct ListNode {
        int val;
        struct ListNode *next;
 };

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static int list_length(struct ListNode *list)
{
        int len = 0;
        while (list != NULL) {
                len++;
                list = list->next;
        }
        return len;
}

struct ListNode * addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        int len1 = list_length(l1);
        int len2 = list_length(l2);

        struct ListNode *lm = len1 > len2 ? l1 : l2;
        struct ListNode *p = lm;

        int sum = 0, c = 0, mod = 0;
        while (l1 != NULL && l2 != NULL) {
                sum = c + l1->val + l2->val;
                c = sum / 10;
                mod = sum % 10;
                
                p->val = mod;

                l1 = l1->next;
                l2 = l2->next;
                p = p->next;
        }

        while (p != NULL) {
                sum = c + p->val;
                c = sum / 10;
                mod = sum % 10;

                p->val = mod;
                p = p->next;

                if (c == 0) break;
        }

        if (c == 1) {
                p = lm;
                while (p->next != NULL) p = p->next;
                struct ListNode *node = malloc(sizeof(struct ListNode));
                node->val = c;
                node->next = NULL;
                p->next = node;
        }

        return lm;
}
// @lc code=end

