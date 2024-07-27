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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1, q1;
        bool ans = true;
        solution(p, q, ans);

        return ans;
    }
    void solution(TreeNode* p, TreeNode* q, bool& ans) {
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
            ans = false;
            return;
        }
        if (p == NULL && q == NULL)
            return;
        if (p->val != q->val)
            ans = false;
        solution(p->left, q->left, ans);
        solution(p->right, q->right, ans);
    }
};