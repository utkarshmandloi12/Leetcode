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
    int ans = 0;

    int sumRootToLeaf(TreeNode *root)
    {
        string s = "";
        calc(root, s);
        return ans;
    }

    string calc(TreeNode *node, string s)
    {
        if (node == nullptr)
            return "";

        string left = calc(node->left, s + to_string(node->val));
        string right = calc(node->right, s + to_string(node->val));

        if (node->left == NULL && node->right == NULL)
        {
            s += to_string(node->val);
            ans += stoi(s, NULL, 2);
        }
        return s + to_string(node->val);
    }
};