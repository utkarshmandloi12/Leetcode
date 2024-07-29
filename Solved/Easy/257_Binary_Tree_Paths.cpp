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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> path;
        calc(root, path, "");
        return path;
    }

    string calc(TreeNode *node, vector<string> &path, string s)
    {
        if (node == NULL)
            return {};

        string left = calc(node->left, path, s + to_string(node->val) + "->");
        string right = calc(node->right, path, s + to_string(node->val) + "->");
        s += to_string(node->val);
        if (node->left == NULL && node->right == NULL)
            path.push_back(s);

        return s + to_string(node->val);
    }
};