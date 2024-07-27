class Solution {
public:
    int maximumLength(vector<int>& nums) {
        long int n = nums.size(), ce = 0, co = 0, c = 1;
        for (long int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                ce++;
            else
                co++;
        }
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] % 2 != nums[i + 1] % 2)
                c++;
        }

        return max(c, max(ce, co));
    }
};