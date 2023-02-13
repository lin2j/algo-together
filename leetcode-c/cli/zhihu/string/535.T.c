/*
 * @lc app=leetcode.cn id=535 lang=c
 *
 * [535] TinyURL 的加密与解密
 *
 * https://leetcode.cn/problems/encode-and-decode-tinyurl/description/
 *
 * algorithms
 * Medium (87.63%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    42.9K
 * Total Submissions: 48.9K
 * Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
 *
 * TinyURL 是一种 URL 简化服务， 比如：当你输入一个 URL
 * https://leetcode.com/problems/design-tinyurl 时，它将返回一个简化的URL
 * http://tinyurl.com/4e9iAk 。请你设计一个类来加密与解密 TinyURL 。
 * 
 * 加密和解密算法如何设计和运作是没有限制的，你只需要保证一个 URL 可以被加密成一个 TinyURL ，并且这个 TinyURL
 * 可以用解密方法恢复成原本的 URL 。
 * 
 * 实现 Solution 类：
 * 
 * 
 * 
 * 
 * Solution() 初始化 TinyURL 系统对象。
 * String encode(String longUrl) 返回 longUrl 对应的 TinyURL 。
 * String decode(String shortUrl) 返回 shortUrl 原本的 URL 。题目数据保证给定的 shortUrl
 * 是由同一个系统对象加密的。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：url = "https://leetcode.com/problems/design-tinyurl"
 * 输出："https://leetcode.com/problems/design-tinyurl"
 * 
 * 解释：
 * Solution obj = new Solution();
 * string tiny = obj.encode(url); // 返回加密后得到的 TinyURL 。
 * string ans = obj.decode(tiny); // 返回解密后得到的原本的 URL 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= url.length <= 10^4
 * 题目数据保证 url 是一个有效的 URL
 * 
 * 
 * 
 * 
 */
#include <stdlib.h>

// @lc code=start
/** Encodes a URL to a shortened URL. */

/*
 * Encode 函数
 * 使用自增 id 作为 longUrl 的键，每接收一个 longUrl 都将 
 * id 加一，将键值对 (id,longUrl) 插入数据库 dataBase，然
 * 后返回带有 id 的字符串作为 shorUrl。
 *
 * Decode 函数
 * 将 shortUrl 转换成对应的 key，然后在数据库 dataBase 中
 * 查找 key 对应的 longUrl。
 *
 * 这个 database 可以使用哈希表代替
 */

char *tmp;
char * encode(char *long_url)
{
        tmp = long_url;
        return tmp;
}

/** Decodes a shortened URL to its original URL. */
char * decode(char *short_url)
{
    
        return tmp;
}

// Your functions will be called as such:
// char* s = encode(s);
// decode(s);
// @lc code=end


