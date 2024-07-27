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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* common = findCommon(root, startValue, destValue);
        string stoc, ctod, ans;
        path(common, startValue, stoc);
        path(common, destValue, ctod);

        ans.append(stoc.length(), 'U');
        ans += ctod;

        return ans;
    }

    TreeNode* findCommon(TreeNode* root, int val1, int val2) {
        if (root == NULL)
            return NULL;
        if (root->val == val1 || root->val == val2)
            return root;

        TreeNode* left = findCommon(root->left, val1, val2);
        TreeNode* right = findCommon(root->right, val1, val2);

        if (left == NULL)
            return right;
        else if (right == NULL)
            return left;
        else
            return root;
    }

    bool path(TreeNode* node, int val, string& s) {
        if (node == NULL)
            return false;
        if (node->val == val)
            return true;
        s += 'L';
        if (path(node->left, val, s))
            return true;
        s.pop_back();
        s += 'R';
        if (path(node->right, val, s))
            return true;
        s.pop_back();

        return false;
    }
};