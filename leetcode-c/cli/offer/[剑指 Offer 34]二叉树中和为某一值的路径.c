//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：[[5,4,11,2],[5,8,4,5]]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：root = [1,2,3], targetSum = 5
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1,2], targetSum = 0
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点总数在范围 [0, 5000] 内 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
//
// 注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/ 
// Related Topics 树 深度优先搜索 回溯 二叉树 👍 357 👎 0

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
#define MAX_LEAF_COUNT 2048
// 退化成链表时，树最大的高度是节点数
#define MAX_PATH_LENGTH 5000

int **ans;
int path[MAX_PATH_LENGTH];
int pos = 0;

void find_path(struct TreeNode *root, int target,
	       int *return_size, int **return_column_sizes)
{
	if (root == NULL)
		return;

	target = target - root->val;
	path[pos++] = root->val;

	if (target == 0 && root->left == NULL && root->right == NULL) {
		(*return_column_sizes)[*return_size] = pos;
		ans[*return_size] = (int *)malloc(sizeof(int) * pos);
		memcpy(ans[*return_size], path, sizeof(int) * pos);
		(*return_size)++;
		pos--;
		return;
	}

	find_path(root->left, target, return_size, return_column_sizes);
	find_path(root->right, target, return_size, return_column_sizes);
	pos--;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int ** pathSum(struct TreeNode *root, int target,
	       int *return_size, int **return_column_sizes)
{
	*return_size = 0;
	if (root == NULL)
		return NULL;

	ans = (int **)malloc(sizeof(int *) * MAX_LEAF_COUNT);
	*return_column_sizes = (int *)malloc(sizeof(int) * MAX_LEAF_COUNT);

	find_path(root, target, return_size, return_column_sizes);

	return ans;
}
//leetcode submit region end(Prohibit modification and deletion)
