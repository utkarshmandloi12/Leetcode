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
    TreeNode *tree(vector<int> &nums, int l, int h) {
        if (l <= h) {
            int mid = l + (h - l) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = tree(nums, l, mid - 1);
            root->right = tree(nums, mid + 1, h);
            return root;
        }
        return NULL;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return tree(nums, 0, nums.size() - 1);
    }
};