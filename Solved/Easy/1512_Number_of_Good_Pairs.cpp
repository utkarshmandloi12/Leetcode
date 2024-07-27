class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(), count = 0, a[100] = {0};

        for (int i = 0; i < n; i++) {
            a[nums[i] - 1]++;
        }

        for (int i = 0; i < 100; i++) {
            count += a[i] * (a[i] - 1) / 2;
        }

        return count;
    }
};