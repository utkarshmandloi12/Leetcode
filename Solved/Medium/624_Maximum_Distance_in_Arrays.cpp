class Solution
{
public:
    int maxDistance(vector<vector<int>> &a)
    {
        int n = a.size(), c = 0;
        int mx = a[0][a[0].size() - 1], mn = a[0][0];

        for (int i = 1; i < n; i++)
        {
            int tmx = a[i].back(), tmn = a[i][0];
            c = max(c, max(mx - tmn, tmx - mn));
            mx = max(mx, tmx), mn = min(mn, tmn);
        }

        return c;
    }
};