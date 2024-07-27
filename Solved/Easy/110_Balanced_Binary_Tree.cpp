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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int height = solution(root, 0, ans);
        return ans;
    }
    int solution(TreeNode* node, int c, bool& ans) {
        if (node == NULL)
            return 0;
        int left = solution(node->left, c + 1, ans);
        int right = solution(node->right, c + 1, ans);
        if (abs(left - right) > 1)
            ans = false;
        return max(left, right) + 1;
    }
};