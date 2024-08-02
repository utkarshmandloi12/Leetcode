class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size(), c = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] == 1)
                c++;
        nums.insert(nums.end(), nums.begin(), nums.end());

        int ans = c, c1 = 0;

        for (int i = 0; i < 2 * n; i++)
        {
            if (nums[i] == 1)
                c1++;
            if (i >= c)
            {
                if (nums[i - c] == 1)
                    c1--;
                ans = min(ans, c - c1);
            }
        }

        return ans;
    }
};