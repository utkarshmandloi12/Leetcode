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
    int countPairs(TreeNode* root, int distance) {
        int count = solution(root, distance)[11];
        return count;
    }

    vector<int> solution(TreeNode* node, int d) {
        if (node == NULL)
            return vector<int>(12);
        else if (!node->left && !node->right) {
            vector<int> a(12);
            a[0] = 1;
            return a;
        }

        vector<int> left = solution(node->left, d);
        vector<int> right = solution(node->right, d);

        vector<int> ans(12);

        for (int i = 0; i < 10; i++) {
            ans[i + 1] = left[i] + right[i];
        }

        ans[11] += left[11] + right[11];

        for (int i = 0; i <= d; i++) {
            for (int j = 0; j <= d; j++) {
                if (2 + i + j <= d)
                    ans[11] += left[i] * right[j];
            }
        }

        return ans;
    }
};