//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。 
//
// 
//
// 参考以下这颗二叉搜索树： 
//
//      5
//    / \
//   2   6
//  / \
// 1   3 
//
// 示例 1： 
//
// 输入: [1,6,3,2,5]
//输出: false 
//
// 示例 2： 
//
// 输入: [1,3,2,6,5]
//输出: true 
//
// 
//
// 提示： 
//
// 
// 数组长度 <= 1000 
// 
// Related Topics 栈 树 二叉搜索树 递归 二叉树 单调栈 👍 567 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

bool __verify_post_order(int *postorder, int l, int r)
{
	if (l >= r)
		return true;

	int p = l;
	while(postorder[p] < postorder[r])
		p++;

	// range of left child is [l, left_end)
	int left_end = p;
	while(postorder[p] > postorder[r])
		p++;

	return p == r
		&& __verify_post_order(postorder, l, left_end - 1)
		&& __verify_post_order(postorder, left_end, r - 1);
}


bool verifyPostorder(int *postorder, int postorder_size)
{
	if (postorder == NULL || postorder_size == 0)
		return true;

	return __verify_post_order(postorder, 0, postorder_size - 1);
}

//leetcode submit region end(Prohibit modification and deletion)
