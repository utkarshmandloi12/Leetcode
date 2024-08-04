class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {

        vector<int> all;
        int sum = 0, wd = 2, id = n, mod = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            int s = 0;
            for (int j = i; j < n; j++)
            {
                s += nums[j];
                all.push_back(s);
            }
        }

        sort(all.begin(), all.end());

        for (int i = left - 1; i < right; i++)
        {
            sum = (sum + all[i]) % mod;
        }

        return sum;
    }
};