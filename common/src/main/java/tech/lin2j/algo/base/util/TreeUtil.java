package tech.lin2j.algo.base.util;

import tech.lin2j.algo.base.ds.TreeNode;

import java.util.Objects;

/**
 * @author linjinjia linjinjia047@163.com
 * @date 2021/4/17 17:09
 */
public class TreeUtil {

    public static TreeNode buildFromString(String arrStr) {
        return buildFromArray(getArray(arrStr));
    }

    private static Integer[] getArray(String arrStr) {
        String[] arr = arrStr.split(",");
        Integer[] result = new Integer[arr.length];
        for(int i = 0; i < arr.length; i++) {
            result[i] = getInteger(arr[i]);
        }
        return result;
    }

    private static Integer getInteger(String digital) {
        if(Objects.equals("null", digital)) {
            return null;
        } else {
            return Integer.parseInt(digital);
        }
    }

    /**
     * 将一个数组转换为二叉树
     *
     * @param arr 数组
     * @return 二叉树根节点
     */
    public static TreeNode buildFromArray(Integer[] arr) {
        if (arr == null || arr.length == 0) {
            return null;
        }
        return getNode(arr, 0);
    }

    private static TreeNode getNode(Integer[] arr, int rootI) {
        if(rootI < arr.length) {
            TreeNode root = getNode(arr[rootI]);
            if(root != null) {
                root.left = getNode(arr, rootI * 2 + 1);
                root.right = getNode(arr, rootI * 2 + 2);
            }
            return root;
        } else {
            return null;
        }
    }

    private static TreeNode getNode(Integer val) {
        return val == null ? null : new TreeNode(val);
    }
}
