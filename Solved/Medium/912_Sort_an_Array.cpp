class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i *= 2) {
            for (int j = 0; j < n - i; j += 2 * i) {
                int h = min(n - 1, j + 2 * i - 1);
                int mid = i + j - 1;
                merger(nums, j, h, mid);
            }
        }

        return nums;
    }

    void merger(vector<int>& nums, int l, int h, int m) {
        vector<int> temp(h - l + 1);
        int id = 0, i = l, j = m + 1;

        while (i <= m && j <= h) {
            if (nums[i] <= nums[j])
                temp[id++] = nums[i++];
            else
                temp[id++] = nums[j++];
        }
        while (i <= m) temp[id++] = nums[i++];
        while (j <= h) temp[id++] = nums[j++];

        for (int i = l; i <= h; i++) {
            nums[i] = temp[i - l];
        }
    }
};