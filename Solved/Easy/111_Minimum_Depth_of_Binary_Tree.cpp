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
    int ans = INT_MAX;
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        calc(root, 0);
        return ans;
    }

    int calc(TreeNode *node, int c)
    {
        if (node == NULL)
            return c;

        int left = calc(node->left, c + 1);
        int right = calc(node->right, c + 1);
        if (node->left == NULL && node->right == NULL)
            ans = min(ans, min(left, right));
        return min(left, right);
    }
};