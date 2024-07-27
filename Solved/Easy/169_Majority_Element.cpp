class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 1, ans = nums[0], max = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                c++;
            } else {
                c = 1;
            }
            if (max < c) {
                max = c;
                ans = nums[i];
            }
        }

        return ans;
    }
};