//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。 
//
// 
//
// 示例 1: 
//
// 输入: "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 
//
// 提示： 
//
// 
// s.length <= 40000 
// 
//
// 注意：本题与主站 3 题相同：https://leetcode-cn.com/problems/longest-substring-without-
//repeating-characters/ 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 484 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int lengthOfLongestSubstring(char* s)
{
        if (s == NULL)
                return 0;

        int map[128];
        for (int i = 0; i < 128; ++i) {
                map[i] = -1;
        }

        int start = -1;
        int ans = 0;

        for(int i = 0; s[i] != '\0'; ++i) {
                char c = s[i];
                if (map[c] != -1)
                        start = MAX(start, map[c]);
                map[c] = i;
                ans = MAX(ans, (i - start));
        }

        return ans;
}

//leetcode submit region end(Prohibit modification and deletion)
