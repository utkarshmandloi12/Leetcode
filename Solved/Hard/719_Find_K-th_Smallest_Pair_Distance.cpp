class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mx = nums[n - 1];

        vector<int> a(mx + 1, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int d = abs(nums[i] - nums[j]);
                a[d]++;
            }
        }

        for (int i = 0; i <= mx; i++)
        {
            k -= a[i];
            if (k <= 0)
                return i;
        }

        return 0;
    }

    int find(vector<int> &a, int l, int h, int num)
    {

        while (l <= h)
        {
            int m = (l + h) / 2;
            cout << m << endl;
            int val = a[m];
            if (val == num)
                return m;
            if (val < num)
                l = m + 1;
            else
                h = m - 1;
        }

        return l;
    }
};