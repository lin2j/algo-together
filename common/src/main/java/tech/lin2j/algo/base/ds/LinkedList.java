package tech.lin2j.algo.base.ds;

import tech.lin2j.algo.base.util.RandomUtil;

import java.util.ArrayList;
import java.util.List;

/**
 * 链表
 *
 * @author linjinjia
 * @date 2020/9/9 21:47
 */
public class LinkedList<T> {

    /**
     * 链表长度
     */
    private int size;

    /**
     * 头结点
     */
    private Node<T> head;

    /**
     * 尾结点
     */
    private Node<T> tail;

    public LinkedList() {
        this.head = this.tail = null;
        this.size = 0;
    }

    public LinkedList(T val) {
        this.head = this.tail = new Node<>(val, null);
        this.size = 1;
    }

    public static void main(String[] args) {
        LinkedList<Integer> linkedList = new LinkedList<>();
        Integer[] integers = RandomUtil.randomIntArray(0, 10, 10);
        for (Integer i : integers) {
            linkedList.add(i);
        }
    }

    /**
     * 返回链表大小
     *
     * @return 链表大小
     */
    public int size() {
        return this.size;
    }

    /**
     * 返回第一个结点的指针，即 head
     * @return 头部节点
     */
    public Node<T> first(){
        return this.head;
    }

    /**
     * 添加一个结点
     *
     * @param val 结点值
     */
    private void add(T val) {
        if (val != null) {
            Node<T> newNode = new Node<>(val, null);
            if (this.head == null) {
                this.head = this.tail = newNode;
            } else {
                this.tail.next = new Node<>(val, null);
                this.tail = this.tail.next;
            }
            ++this.size;
        }
    }

    /**
     * 添加一个数组
     *
     * @param ts 数组
     */
    public void addAll(T[] ts) {
        for (T t : ts) {
            add(t);
        }
    }

    /**
     * 添加可迭代的对象
     */
    public void addAll(Iterable<T> iterable) {
        if (iterable != null) {
            for (T t : iterable) {
                add(t);
            }
        }
    }

    public void delete(T val){

    }

    @Override
    public String toString() {
        return this.head.toString();
    }

    /**
     * 链表结点
     *
     * @param <T>
     */
    public static class Node<T> {
        /**
         * 结点值
         */
        private T val;

        /**
         * 下一个结点的指向
         */
        private Node<T> next;

        public Node(T val){
            this.val = val;
        }

        public Node(T val, Node<T> next) {
            this.val = val;
            this.next = next;
        }

        public T getVal() {
            return val;
        }

        public void setVal(T val) {
            this.val = val;
        }

        public Node<T> getNext() {
            return next;
        }

        public void setNext(Node<T> next) {
            this.next = next;
        }

        /**
         * 通过递归遍历节点收集结点值
         */
        @Override
        public String toString() {
            List<String> list = new ArrayList<>();
            Node<T> node = this;
            while (node != null) {
                list.add(node.val.toString());
                node = node.next;
            }
            return String.join(",", list);
        }
    }
}
