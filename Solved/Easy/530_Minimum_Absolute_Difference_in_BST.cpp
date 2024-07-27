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
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> val;
        solution(root, val);
        sort(val.begin(), val.end());
        int mindiff = INT_MAX;
        for (int i = 1; i < val.size(); i++)
        {
            mindiff = min(mindiff, abs(val[i] - val[i - 1]));
        }

        return mindiff;
    }

    void solution(TreeNode *node, vector<int> &val)
    {
        if (node == NULL)
            return;

        solution(node->left, val);
        solution(node->right, val);

        val.push_back(node->val);
    }
};