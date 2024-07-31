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
    bool isValidBST(TreeNode *root)
    {
        return find(root, -10000000000, 10000000000);
    }

    bool find(TreeNode *node, long long mn, long long mx)
    {
        if (node == nullptr)
            return true;
        if (node->val > mn && node->val < mx)
            return find(node->right, node->val, mx) && find(node->left, mn, node->val);

        else
            return false;
    }
};