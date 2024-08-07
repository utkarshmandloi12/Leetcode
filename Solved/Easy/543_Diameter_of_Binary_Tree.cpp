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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        int val = calc(root, ans);
        return ans;
    }

    int calc(TreeNode *node, int &ans)
    {
        if (node == NULL)
            return 0;

        int left = calc(node->left, ans);
        int right = calc(node->right, ans);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
};