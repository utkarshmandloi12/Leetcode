class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c = 0, n = nums.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        for (auto i : mp) {
            nums[c++] = i.first;
        }

        return c;
    }
};