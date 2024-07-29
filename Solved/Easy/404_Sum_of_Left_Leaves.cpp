/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        calc(root, sum);
        return sum;
    }

    int calc(TreeNode *node, int &sum)
    {
        if (node == NULL)
            return 0;

        int left = calc(node->left, sum);
        int right = calc(node->right, sum);

        if (node->left != NULL && (node->left->left == NULL && node->left->right == NULL))
            sum += node->left->val;

        return sum;
    }
};