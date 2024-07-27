class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        map<int, int> mp;
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        for (auto i : mp) a.push_back(i);

        sort(a.begin(), a.end(), [&](auto& a, auto& b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        });

        for (auto i : a) {
            int c = 0;
            while (c++ != i.second) ans.push_back(i.first);
        };

        return ans;
    }
};