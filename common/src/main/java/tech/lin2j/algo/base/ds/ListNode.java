package tech.lin2j.algo.base.ds;

/**
 * @author linjinjia
 * @date 2021/5/27 14:15
 */
public class ListNode {
    public int val;
    public ListNode next;

    public ListNode() {
    }

    public ListNode(int val) {
        this.val = val;
    }

    public ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}