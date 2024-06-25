/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (39.88%)
 * Total Accepted:    2.9M
 * Total Submissions: 7.3M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

#include <stdlib.h>
#include "uthash.h"

// @lc code=start

#define UNIQ -1

typedef struct {
        int key;
        int idx;
        UT_hash_handle hh;
} hash_map;

/*
 * 将 key 和 value 保存到哈希表中，保存之前会检查是否已存在对应的key，
 * 如果已存在，则会将对应的 value 返回，否则返回 -1
 */
static int put_map(hash_map **map, int ikey, int idx)
{
        hash_map *node = NULL;
        HASH_FIND_INT(*map, &ikey, node);
        if (node == NULL) {
                node = malloc(sizeof(hash_map));
                node->key = ikey;
                node->idx = idx;
                HASH_ADD_INT(*map, key, node);
        } else {
                int old_idx = node->idx;
                node->idx = idx;
                return old_idx;
        }

        return UNIQ;
}

static void free_map(hash_map **map)
{
        hash_map *node = NULL, *tmp = NULL;
        HASH_ITER(hh, *map, node, tmp) {
                HASH_DEL(*map, node);
                free(node);
        }
}

/*
 * 0. 使用变量 max_len 记录长度
 * 1. 使用两条指针b、e指向子串的开头和结尾，再使用一个哈希表记录字符是否出现过
 * 2. 当 e 指向下一个字符时，判断集合是否存在该字符（存在，且对应位置在 b 或之后）
 *      2.1 如果不存在，则字符进入哈希表，key 为字符，value 为索引位置
 * 3. 当发现哈希表中已存在该字符，得到长度 len = e - 1 - b, 与最大长度相比，同时
 *    将 s 指向哈希表中已存在字符的下一位
 * 4. 当 e 到指向 '\0' 时，退出循环，同时再计算一次长度
 */
int lengthOfLongestSubstring(char *s) 
{
        if (s == NULL || s[0] == '\0') return 0;
        if (s[1] == '\0') return 1;
    
        int max_len = 0;
        hash_map *map = NULL;
        int b = 0, e = 0;
        for (; s[e] != '\0'; e++) {
                int idx = put_map(&map, s[e], e);

                if (idx != UNIQ && idx >= b) {
                        int len = e - b;
                        b = idx + 1;
                        max_len = len > max_len ? len : max_len;
                }
        }

        int len = e - b;
        max_len = len > max_len ? len : max_len;

        free_map(&map);

        return max_len;
}
// @lc code=end

