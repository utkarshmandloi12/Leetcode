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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        vector<TreeNode*> rootlist;

        root = remove(root, del, rootlist);
        if (root)
            rootlist.push_back(root);

        return rootlist;
    }

    TreeNode* remove(TreeNode* root, vector<int>& del, vector<TreeNode*>& list) {
        if (root == NULL)
            return NULL;

        root->left = remove(root->left, del, list);
        root->right = remove(root->right, del, list);

        if (find(del.begin(), del.end(), root->val) != del.end()) {
            if (root->right != NULL)
                list.push_back(root->right);
            if (root->left != NULL)
                list.push_back(root->left);
            delete root;
            return nullptr;
        }

        return root;
    }
};