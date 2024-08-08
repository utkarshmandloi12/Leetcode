class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &m)
    {
        int r = m.size(), c = m[0].size();
        int rc = 0, cc = 0, i = 0, n = r * c, rows = 0, cols = 0;

        vector<int> ans;

        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (ans.size() < n)
        {
            while (rc >= rows && rc < r && cc >= cols && cc < c)
            {
                ans.push_back(m[rc][cc]);
                rc += dir[i][0];
                cc += dir[i][1];
            }
            rc -= dir[i][0], cc -= dir[i][1];
            if (i == 0)
                rows++;
            if (i == 1)
                c--;
            if (i == 2)
                r--;
            if (i == 3)
                cols++;

            i = (i + 1) % 4;
            rc += dir[i][0], cc += dir[i][1];
        }

        return ans;
    }
};