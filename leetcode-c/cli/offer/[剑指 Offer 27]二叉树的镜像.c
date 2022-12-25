//请完成一个函数，输入一个二叉树，该函数输出它的镜像。 
//
// 例如输入： 
//
// 4 
// / \ 
// 2 7 
// / \ / \ 
//1 3 6 9 
//镜像输出： 
//
// 4 
// / \ 
// 7 2 
// / \ / \ 
//9 6 3 1 
//
// 
//
// 示例 1： 
//
// 输入：root = [4,2,7,1,3,6,9]
//输出：[4,7,2,9,6,3,1]
// 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 1000 
//
// 注意：本题与主站 226 题相同：https://leetcode-cn.com/problems/invert-binary-tree/ 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 281 👎 0

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


struct TreeNode * mirrorTree(struct TreeNode *root)
{
	if (root == NULL)
		return NULL;

	struct TreeNode * new_root =
		(struct TreeNode *)malloc(sizeof(struct TreeNode));
	new_root->val = root->val;
	new_root->left = mirrorTree(root->right);
	new_root->right = mirrorTree(root->left);

	return new_root;
}

//leetcode submit region end(Prohibit modification and deletion)
