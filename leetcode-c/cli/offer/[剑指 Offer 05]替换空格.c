//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 
//
// 
//
// 示例 1： 
//
// 输入：s = "We are happy."
//输出："We%20are%20happy." 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 10000 
// Related Topics 字符串 👍 314 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


char* replaceSpace(char* s){
	if (s == NULL)
		return s;

	char *p = s;
	uint32_t num_space = 0;
	uint32_t s_len = 0;
	while (*p != '\0') {
		if (*p == ' ')
			num_space++;
		s_len++;
		p++;
	}

	if(num_space == 0)
		return s;

	uint32_t new_len = s_len + 2 * num_space;
	char *arr = malloc(sizeof(char) * new_len + 1);
	char *ans = arr;
	while (*s != '\0') {
		if (*s == ' ') {
			*arr++ = '%';
			*arr++ = '2';
			*arr++ = '0';
		} else {
			*arr = *s;
			arr++;
		}
		s++;
	}
	*arr = '\0';
	return ans;
}

//leetcode submit region end(Prohibit modification and deletion)
