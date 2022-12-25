//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。 
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
//  [20,9],
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
// Related Topics 树 广度优先搜索 二叉树 👍 239 👎 0

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

#define MAX_SIZE 1010



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode *root, int *return_size,
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

	bool odd = true;
	while(head < tail) {
		int size = tail - head;
		(*return_column_sizes)[*return_size] = size;
		ans[*return_size] = (int *)malloc(sizeof(int) * size);

		for (int i = 0; i < size; i++) {
			struct TreeNode *node = queue[head++];
			int idx = odd ? i : size - i - 1;
			ans[*return_size][idx] = node->val;

			if (node->left != NULL)
				queue[tail++] = node->left;
			if (node->right != NULL)
				queue[tail++] = node->right;
		}

		odd = !odd;
		(*return_size)++;
	}

	return ans;
}

//leetcode submit region end(Prohibit modification and deletion)
