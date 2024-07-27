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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        bool ans = false;
        solution(root, targetSum, 0, ans);
        return ans;
    }

    void solution(TreeNode *node, int t, int sum, bool &ans)
    {
        if (node == NULL)
            return;

        solution(node->left, t, sum + node->val, ans);
        solution(node->right, t, sum + node->val, ans);
        if (sum + node->val == t && node->left == NULL && node->right == NULL)
            ans = true;
    }
};