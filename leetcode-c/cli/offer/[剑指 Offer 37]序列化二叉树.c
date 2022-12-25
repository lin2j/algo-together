//请实现两个函数，分别用来序列化和反序列化二叉树。 
//
// 你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字
//符串反序列化为原始的树结构。 
//
// 提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方
//法解决这个问题。 
//
// 
//
// 示例： 
//
// 
//输入：root = [1,2,3,null,null,4,5]
//输出：[1,2,3,null,null,4,5]
// 
//
// 
//
// 注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-
//binary-tree/ 
// Related Topics 树 深度优先搜索 广度优先搜索 设计 字符串 二叉树 👍 314 👎 0

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//leetcode submit region begin(Prohibit modification and deletion)
#define MAX_SIZE 80000
#define EMPTY "[]"
#define DELIM ","

/*
 * solve:
 * runtime error: member access within misaligned address
 * 0xbebebebebebebebe for type 'struct TreeNode'.
 *
 * because when calling malloc to create a tree node, its
 * left and right child is pointing to unknown address, so
 * the program will crash when testing in leetcode platform.
 */
static void init_node(struct TreeNode *node)
{
        node->left = NULL;
        node->right = NULL;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
char * serialize(struct TreeNode *root)
{
        if (root == NULL)
                return EMPTY;

        struct TreeNode *queue[MAX_SIZE] = {0};
        char *ans = (char *)malloc(sizeof(char) * MAX_SIZE);
        memset(ans, 0, MAX_SIZE);
        char val[10] = {0};
        int head = 0;
        int tail = 0;
        queue[tail++] = root;

        ans[0] = '[';

        while(head < tail) {
                struct TreeNode *node = queue[head++];
                if (node == NULL) {
                        strcat(ans, "#");
                } else {
                        sprintf(val, "%d", node->val);
                        strcat(ans, val);
                        memset(val, 0, 10);

                        queue[tail++] = node->left;
                        queue[tail++] = node->right;
                }
                strcat(ans, DELIM);
        }
        int len = strlen(ans);
        ans[len-1] = ']';
        return ans;
}

/** Decodes your encoded data to tree. */
struct TreeNode * deserialize(char *data)
{
        if (strcmp(data, EMPTY) == 0)
                return NULL;

        // remove the [ and ]
        data++;
        int len = strlen(data);
        data[len-1] = '\0';

        struct TreeNode *queue[MAX_SIZE] = {0};
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        int head = 0;
        int tail = 0;
        queue[tail++] = root;
        init_node(root);

        char *val = strtok(data, DELIM);
        root->val = atoi(val);

        while(head < tail) {
                struct TreeNode *node = queue[head++];
                val = strtok(NULL, DELIM);
                if (strcmp(val, "#") != 0) {
                        node->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                        node->left->val = atoi(val);
                        init_node(node->left);
                        queue[tail++] = node->left;
                }
                val = strtok(NULL, DELIM);
                if (strcmp(val, "#") != 0) {
                        node->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                        node->right->val = atoi(val);
                        init_node(node->right);
                        queue[tail++] = node->right;
                }
        }

        return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
//leetcode submit region end(Prohibit modification and deletion)
