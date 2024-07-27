class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int mini = nums[0];
        int sum = nums[0];
        int sum2 = nums[0];
        int tot = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 1; i < n; i++) {
            if (sum < 0)
                sum = nums[i];
            else
                sum += nums[i];
            if (sum2 > 0)
                sum2 = nums[i];
            else
                sum2 += nums[i];
            maxi = max(sum, maxi);
            mini = min(mini, sum2);
        }
        return (tot == mini) ? maxi : max(tot - mini, maxi);
    }
};