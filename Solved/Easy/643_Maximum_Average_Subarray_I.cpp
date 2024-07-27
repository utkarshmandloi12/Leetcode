class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double avg = 0, sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        avg = sum;
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            avg = max(avg, sum);
        }

        return avg / k;
    }
};