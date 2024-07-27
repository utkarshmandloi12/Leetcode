/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) { return depth(root, 0); }

    int depth(TreeNode* node, int c) {
        if (node == NULL)
            return c;
        int left = depth(node->left, c + 1);
        int right = depth(node->right, c + 1);
        return max(left, right);
    }
};