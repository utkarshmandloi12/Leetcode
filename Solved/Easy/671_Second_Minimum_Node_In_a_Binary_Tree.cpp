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
    bool c = true;
    int findSecondMinimumValue(TreeNode *node)
    {
        if (node->left == NULL)
            return -1;
        long long ans = 10000000000;
        find(node, node->val, ans);

        if (c)
            return -1;
        return ans;
    }

    void find(TreeNode *node, int mn, long long &ans)
    {
        if (node == NULL)
            return;

        if (node->val > mn && ans > node->val)
            ans = node->val, c = false;

        find(node->left, mn, ans);
        find(node->right, mn, ans);
    }
};
