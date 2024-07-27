class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> idx;
        int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                idx.push_back(i);
                c++;
            }
        }

        vector<int> ans;

        if (c == 0) {
            ans.push_back(-1), ans.push_back(-1);
            return ans;
        }

        ans.push_back(idx[0]), ans.push_back(idx[idx.size() - 1]);
        return ans;
    }
};