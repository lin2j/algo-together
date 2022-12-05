package tech.lin2j.algo.base.ds;

import java.util.List;

/**
 * @author linjinjia linjinjia047@163.com
 * @date 2021/4/15 21:43
 */
public class Node {
    public int val;
    public List<Node> children;
    public Node random;
    public Node next;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }

    public Node(int val, Node left, Node right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
