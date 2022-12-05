package tech.lin2j.algo.base.util;

/**
 * 数组工具类
 * @author linjinjia
 * @date 2020/9/28 18:04
 */
public class ArrayUtil {

    private ArrayUtil(){}

    public static Integer min(Integer[] a){
        if(a == null || a.length == 0 ){
            return null;
        }
        int min = a[0];
        for (Integer i : a){
            if(i < min){
                min = i;
            }
        }
        return min;
    }

    /**
     * 反转数组在某个区间的元素
     * @param arr   数组
     * @param l     左边界
     * @param r     右边界
     * @param <T>   元素类型
     */
    public static <T> void reverse(T[] arr, int l, int r){
        while(l < r){
            swap(arr, l++, r--);
        }
    }

    /**
     * 交换数组的两个位置的元素值
     * @param arr 数组
     * @param i   位置1
     * @param j   位置2
     * @param <T> 元素类型
     */
    private static <T> void swap(T[] arr, int i, int j){
        T tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
