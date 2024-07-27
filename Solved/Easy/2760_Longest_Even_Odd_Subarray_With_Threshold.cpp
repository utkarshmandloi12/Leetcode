class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int t) {
        int n = nums.size(), c = 0, e = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (e == 0) {
                if (nums[i] % 2 == 0 && nums[i] <= t)
                    e = 1, c = 1;

            } else if (e == 1) {
                if (nums[i - 1] % 2 != nums[i] % 2 && nums[i] <= t && nums[i - 1] <= t)
                    c++;
                else
                    e = 0, i--;
            }
            ans = max(ans, c);
        }
        return ans;
    }
};