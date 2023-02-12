/*
 * @lc app=leetcode.cn id=451 lang=c
 *
 * [451] 根据字符出现频率排序
 *
 * https://leetcode.cn/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (72.05%)
 * Likes:    459
 * Dislikes: 0
 * Total Accepted:    119.4K
 * Total Submissions: 165.6K
 * Testcase Example:  '"tree"'
 *
 * 给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。
 * 一个字符出现的 频率 是它出现在字符串中的次数。
 * 
 * 返回 已排序的字符串 。如果有多个答案，返回其中任何一个。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "tree"
 * 输出: "eert"
 * 解释: 'e'出现两次，'r'和't'都只出现一次。
 * 因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "cccaaa"
 * 输出: "cccaaa"
 * 解释: 'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
 * 注意"cacaca"是不正确的，因为相同的字母必须放在一起。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "Aabb"
 * 输出: "bbAa"
 * 解释: 此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
 * 注意'A'和'a'被认为是两种不同的字符。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 5 * 10^5
 * s 由大小写英文字母和数字组成
 * 
 * 
 */
#include <stdlib.h>
#include "./include/uthash.h"

// @lc code=start

typedef struct {
        char c;
        int freq;
} pair;

static inline int cmp_pair(const void *a, const void *b)
{
        return ((pair *)b)->freq - ((pair *)a)->freq;
}

/*
 * 定义结构体 pair 用来存储字符以及对应的频数
 *
 * 创建 pair 数组，先遍历 s，统计每个字符的频数放入 pair 数组中
 *
 * 根据频数对 pair 数组进行排序
 *
 * 根据排序结果进行字符串构造
 *
 * T(n): O(n + klogk) k 为 s 中不重复的字符，需要 k 个频数进行排序
 * S(n): O(n + logk) k 为 s 中不重复的字符
 */
char * frequencySort(char *s)
{
        int cnt[128] = {0};
        int c = 0;
        for (int i = 0; s[i] != '\0'; i++) {
                if (cnt[s[i]] == 0) c++;
                cnt[s[i]]++;
        }

        pair freqs[c];
        int k = 0;
        for (int i = 0; i < 128; i++) {
                if (cnt[i] == 0) continue;
                pair p = {.c = i, .freq = cnt[i]};
                freqs[k++] = p;
        }

        qsort(freqs, c, sizeof(pair), cmp_pair);

        k = 0;
        for (int i = 0; i < c; i++) {
                pair p = freqs[i]; 
                for (int j = 0; j < p.freq; j++)
                        s[k++] = p.c;
        }
        
        return s;
}
// @lc code=end


