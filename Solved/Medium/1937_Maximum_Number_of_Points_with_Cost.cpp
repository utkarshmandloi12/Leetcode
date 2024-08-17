class Solution
{
public:
    long long maxPoints(vector<vector<int>> &p)
    {
        int r = p.size(), c = p[0].size();
        long long ans = 0;

        vector<long long> cur(c), prev(c);

        for (int i = 0; i < c; i++)
            prev[i] = p[0][i];

        for (int i = 0; i < r - 1; i++)
        {
            vector<long long> left(c), right(c);

            left[0] = prev[0];
            for (int j = 1; j < c; j++)
                left[j] = max(left[j - 1] - 1, prev[j]);

            right[c - 1] = prev[c - 1];
            for (int j = c - 2; j >= 0; j--)
                right[j] = max(right[j + 1] - 1, prev[j]);

            for (int j = 0; j < c; j++)
            {
                cur[j] = p[i + 1][j] + max(left[j], right[j]);
            }

            prev = cur;
        }

        for (int i = 0; i < c; i++)
            ans = max(ans, prev[i]);

        return ans;
    }
};