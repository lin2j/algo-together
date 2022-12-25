//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。 
//
// 
//
// 例如: 
//给定二叉树: [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回： 
//
// [3,9,20,15,7]
// 
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 1000 
// 
// Related Topics 树 广度优先搜索 二叉树 👍 223 👎 0

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

#define MAX_SIZE 1000

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* levelOrder(struct TreeNode *root, int *return_size){
	*return_size = 0;
	if (root == NULL)
		return NULL;

	int *ans = (int *)malloc(sizeof(int) * MAX_SIZE);
	struct TreeNode *queue[MAX_SIZE] = {0};
	int head = 0;
	int tail = 0;
	queue[tail++] = root;

	while(head < tail) {
		struct TreeNode *node = queue[head++];
		ans[(*return_size)++] = node->val;

		if (node->left != NULL)
			queue[tail++] = node->left;
		if (node->right != NULL)
			queue[tail++] = node->right;
	}

	return ans;
}

//leetcode submit region end(Prohibit modification and deletion)
