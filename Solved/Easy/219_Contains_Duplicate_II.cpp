class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        bool ans = false;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (!mp[nums[i]])
                mp[nums[i]] = 1;
            else
                mp[nums[i]]++;
            if (i > k) {
                mp[nums[i - k - 1]]--;
            }
            if (mp[nums[i]] > 1)
                return true;
        }
        return false;
    }
};