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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        TreeNode* root;
        // TreeNode* temp;

        unordered_set<int> parent, child;
        unordered_map<int, vector<pair<int, int>>> link;
        queue<TreeNode*> ans;

        int n = d.size();

        for (int i = 0; i < n; i++) {
            parent.insert(d[i][0]), parent.insert(d[i][0]);
            child.insert(d[i][1]);
            link[d[i][0]].emplace_back(d[i][1], d[i][2]);
        }

        for (auto i : parent) {
            if (child.find(i) == child.end())
                root = new TreeNode(i);
        }

        ans.push(root);

        while (!ans.empty()) {
            TreeNode* temp = ans.front();
            ans.pop();
            for (auto i : link[temp->val]) {
                TreeNode* ch = new TreeNode(i.first);
                ans.push(ch);
                if (i.second == 1)
                    temp->left = ch;
                else if (i.second == 0)
                    temp->right = ch;
            }
        }
        return root;
    }
};