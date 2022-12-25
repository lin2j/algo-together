//输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。 
//
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。 
//
// 
//
// 示例 1: 
//
// 
//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//Input: preorder = [-1], inorder = [-1]
//Output: [-1]
// 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
//preorder-and-inorder-traversal/ 
// Related Topics 树 数组 哈希表 分治 二叉树 👍 849 👎 0
//

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
 * find the index of the target number in inorder array
 */
int inorder_find_root(int *inorder, int start, int end, int target)
{
	while(start <= end) {
		if (inorder[start] == target)
			return start;
		start++;
	}

	return -1;
}

struct TreeNode * __build_tree(int *preorder, int pre_start, int pre_end,
			       int *inorder, int in_start, int in_end)
{
	if (pre_start > pre_end || in_start > in_end)
		return NULL;

	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = preorder[pre_start];
	int root_index = inorder_find_root(inorder, in_start,
					   in_end, root->val);
	int num_left = root_index - in_start;
	root->left = __build_tree(preorder, pre_start + 1, pre_start + num_left,
				  inorder, in_start, root_index - 1);
	root->right = __build_tree(preorder, pre_start + num_left + 1, pre_end,
				   inorder, root_index + 1, in_end);

	return root;
}


struct TreeNode * buildTree(int *preorder, int preorder_size,
			   int *inorder, int inorder_size)
{
	if (preorder_size == 0 || inorder_size == 0)
		return NULL;
	return __build_tree(preorder, 0, preorder_size - 1,
			    inorder, 0, inorder_size - 1);
}

//leetcode submit region end(Prohibit modification and deletion)
