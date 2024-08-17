class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        int ans = 0, mx = 0;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, mx + values[i] - i);
            mx = max(mx, values[i] + i);
        }

        return ans;
    }
};