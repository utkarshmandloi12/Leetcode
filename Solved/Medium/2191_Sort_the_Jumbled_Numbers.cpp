class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> nums2(n);

        for (int i = 0; i < n; i++) {
            int temp = 0, c = 1, num = nums[i];
            while (num > 0) {
                int val = mapping[num % 10];
                temp += val * c;
                c *= 10;
                num /= 10;
            }
            if (nums[i] == 0)
                nums2[i].first = mapping[0];
            else
                nums2[i].first = temp;
            nums2[i].second = nums[i];
        }

        sort(nums2.begin(), nums2.end(),
             [&](auto a, auto b) { return a.first < b.first; });

        for (int i = 0; i < n; i++) {
            nums[i] = nums2[i].second;
            cout << nums2[i].first << " ";
        }

        return nums;
    }
};