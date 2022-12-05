package tech.lin2j.algo.base.util;

import java.util.Arrays;

/**
 * @author linjinjia
 * @date 2020/9/23 10:24
 */
public class RandomUtil {
    /**
     * 数字
     */
    public static final String NUMBER = "0123456789";

    /**
     * 字母
     */
    public static final String ALPHABET = "abcdefghijklmnopqrstuvwxyz";

    /**
     * 基本字符
     */
    public static final String BASE_STRING = NUMBER + ALPHABET;

    private RandomUtil() {
    }

    /**
     * 产生一个随机数
     *
     * @param min 下界
     * @param max 上界（不包含）
     * @return 介于 [min, max) 的随机数
     */
    public static int randomInt(int min, int max) {
        return (int) (max * Math.random()) + min;
    }

    /**
     * 判断一个数字有没有超出范围
     *
     * @param target 待判断数字
     * @param min    下界
     * @param max    上界
     * @return 当且仅当 target 小于 min 或者 target 大于 max，返回 true
     */
    private static boolean outOfRange(int target, int min, int max) {
        return target < min || target > max;
    }

    /**
     * 产生固定长度的整形数组，元素为随机数
     *
     * @param min  元素值的下界
     * @param max  元素值的上界（不包含该值）
     * @param size 数组长度
     * @return 整形数组
     */
    public static Integer[] randomIntArray(int min, int max, int size) {
        Integer[] ret = new Integer[size];
        for (int i = 0; i < size; i++) {
            ret[i] = randomInt(min, max);
        }
        return ret;
    }

    /**
     * 产生随机长度的随机数组
     *
     * @param min     元素值的下界
     * @param max     元素值的上界（不包含该值）
     * @param minSize 数组长度的下界
     * @param maxSize 数组长度的上界（不包含该值）
     * @return 整形随机长度数组
     */
    public static Integer[] randomSizeIntArray(int min, int max, int minSize, int maxSize) {
        int size = randomInt(minSize, maxSize);
        return randomIntArray(min, max, size);
    }

    /**
     * 返回一个旋转数组
     * @param min     元素值的下界
     * @param max     元素值的上界（不包含该值）
     * @param minSize 数组长度的下界
     * @param maxSize 数组长度的上界（不包含该值）
     * @param sort    产生的数组是否有序
     * @return 整形随机长度数组
     */
    public static Integer[] rotateArray(int min, int max, int minSize, int maxSize, boolean sort){
        Integer[] array = randomSizeIntArray(min, max, minSize, maxSize);
        if(array.length == 0 || array.length == 1){
            return array;
        }
        if(sort){
            Arrays.sort(array);
        }
        int rotateIndex = RandomUtil.randomInt(0, array.length);

        ArrayUtil.reverse(array, 0, rotateIndex - 1);
        ArrayUtil.reverse(array, rotateIndex, array.length - 1);
        ArrayUtil.reverse(array, 0, array.length - 1);

        return array;
    }


    public static void main(String[] args) {
        for (int i = 0; i < 10; i++){
            Integer[] arr = rotateArray(0, 10, 0, 10, true);
            System.out.println(Arrays.toString(arr));
        }
    }

    /**
     * 行递增、列递增的二维数组
     *
     * @return 二维数组
     */
    public static int[][] increaseRowAndColArray(int row, int col) {
        if (row <= 0 || col <= 0) {
            return null;
        }
        int[][] ret = new int[row][col];
        ret[0][0] = randomInt(0, 20);

        for (int i = 1; i < row; i++) {
            ret[i][0] = ret[i - 1][0] + 1;
        }

        for (int r = 0; r < row; r++) {
            for (int c = 1; c < col; c++) {
                ret[r][c] = ret[r][c - 1] + 1;
            }
        }

        return ret;
    }

    /**
     * 基于已有字符生成随机字符串
     *
     * @param baseStr 已有字符
     * @param length  生成的字符串的长度
     * @return 随机字符串
     */
    public static String randomString(String baseStr, int length) {
        int min = 0;
        int max = baseStr.length();
        char[] ret = new char[length];
        for (int i = 0; i < length; i++) {
            ret[i] = baseStr.charAt(randomInt(min, max));
        }

        return new String(ret);
    }

    /**
     * 生成长度固定的随机字符串
     *
     * @param length 生成的字符串的长度
     * @return 随机字符串
     */
    public static String randomString(int length) {
        return randomString(BASE_STRING, length);
    }

    /**
     * 生成包含大写字母的长度固定的随机字符串
     *
     * @param length 生成的字符串的长度
     * @return 随机字符串
     */
    public static String randomUpper(int length) {
        return randomString(ALPHABET, length).toUpperCase();
    }

    /**
     * 获得随机Boolean值
     *
     * @return true or false
     */
    public static Boolean randomBoolean(){
        return 0 == randomInt(0, 2);
    }

}
