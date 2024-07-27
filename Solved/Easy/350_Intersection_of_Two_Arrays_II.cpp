class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, pair<int, int>> a;
        vector<int> arr;

        for (auto i : nums1) a[i].first++;
        for (auto i : nums2) a[i].second++;

        for (auto i : a) {
            int temp = min(i.second.first, i.second.second);
            while (temp--) arr.push_back(i.first);
        }

        return arr;
    }
};