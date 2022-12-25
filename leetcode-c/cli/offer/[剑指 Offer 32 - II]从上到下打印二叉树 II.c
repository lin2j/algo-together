//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。 
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
// 返回其层次遍历结果： 
//
// [
//  [3],
//  [9,20],
//  [15,7]
//]
// 
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 1000 
// 
//
// 注意：本题与主站 102 题相同：https://leetcode-cn.com/problems/binary-tree-level-order-
//traversal/ 
// Related Topics 树 广度优先搜索 二叉树 👍 241 👎 0

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

/* 1010 是为了容错 */
#define MAX_SIZE 1010

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrder(struct TreeNode *root, int *return_size,
		 int **return_column_sizes)
{
	*return_size = 0;
	if (root == NULL)
		return NULL;

	int **ans = (int **)malloc(sizeof(int *) * MAX_SIZE);
	*return_column_sizes = (int *)malloc(sizeof(int *) * MAX_SIZE);
	struct TreeNode *queue[MAX_SIZE] = {0};
	int head = 0;
	int tail = 0;
	queue[tail++] = root;

	while (head < tail) {
		int size = tail - head;
		(*return_column_sizes)[*return_size] = size;
		ans[*return_size] = (int *)malloc(sizeof(int) * size);
		for(int k = 0; k < size; k++) {
			struct TreeNode *node = queue[head++];
			ans[*return_size][k] = node->val;

			if (node->left != NULL)
				queue[tail++] = node->left;
			if (node->right != NULL)
				queue[tail++] = node->right;
		}

		(*return_size)++;
	}

	return ans;
}

//leetcode submit region end(Prohibit modification and deletion)
