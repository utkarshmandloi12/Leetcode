/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *ans;
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        getref(cloned, target);
        return ans;
    }

    void getref(TreeNode *node, TreeNode *target)
    {
        if (node == nullptr)
            return;
        if (node->val == target->val)
            ans = node;

        getref(node->left, target);
        getref(node->right, target);
    }
};