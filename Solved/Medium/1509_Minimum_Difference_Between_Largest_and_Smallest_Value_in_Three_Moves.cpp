class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4)
            return 0;
        partial_sort(nums.begin(), nums.begin() + 4, nums.end());
        nth_element(nums.begin() + 4, nums.begin() + n - 4, nums.end());
        sort(nums.begin() + n - 4, nums.end());
        return min(min(nums[n - 4] - nums[0], nums[n - 1] - nums[3]),
                   min(nums[n - 3] - nums[1], nums[n - 2] - nums[2]));
    }
};