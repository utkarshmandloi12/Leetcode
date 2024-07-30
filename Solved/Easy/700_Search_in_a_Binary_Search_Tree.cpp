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
    TreeNode *ans;
    TreeNode *searchBST(TreeNode *root, int val)
    {
        find(root, val);
        return ans;
    }

    void find(TreeNode *node, int val)
    {
        if (node == nullptr)
            return;
        if (node->val > val)
            find(node->left, val);
        if (node->val < val)
            find(node->right, val);
        if (node->val == val)
            ans = new TreeNode(node->val, node->left, node->right);

        return;
    }
};