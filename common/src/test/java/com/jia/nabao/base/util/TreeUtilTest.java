package com.jia.nabao.base.util;

import tech.lin2j.algo.base.ds.TreeNode;
import org.junit.Test;
import tech.lin2j.algo.base.util.TreeUtil;

/**
 * @author linjinjia linjinjia047@163.com
 * @date 2021/4/17 17:53
 */
public class TreeUtilTest {


    @Test
    public void buildFromArrayTest() {
        Integer[] arr = {3, 5, 1, 6, 2, 9, 8, null, null, 7, 4};
        TreeNode root = TreeUtil.buildFromArray(arr);
        System.out.println(root);
    }
}
