class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        int id = -1;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i - 1] != nums[i] - 1)
                id = i - 1;
            if (i >= k - 1)
            {
                if (id >= i - k + 1)
                    ans.push_back(-1);
                else
                    ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};