class Solution
{
public:
    long long maxEnergyBoost(vector<int> &a, vector<int> &b)
    {
        int n = a.size();

        vector<long long> a1(n), b1(n);
        a1[0] = a[0], b1[0] = b[0];

        for (int i = 1; i < n; i++)
        {
            a1[i] = max(a1[i - 1] + a[i], (i > 1 ? b1[i - 2] : 0) + a[i]);
            b1[i] = max(b1[i - 1] + b[i], (i > 1 ? a1[i - 2] : 0) + b[i]);
        }

        return max(a1[n - 1], b1[n - 1]);
    }
};