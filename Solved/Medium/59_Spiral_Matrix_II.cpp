class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {

        vector<vector<int>> ans(n, vector<int>(n));

        int r = n, c = n, num = 1;
        int rc = 0, cc = 0, i = 0, rows = 0, cols = 0;

        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (num <= n * n)
        {
            while (rc >= rows && rc < r && cc >= cols && cc < c)
            {
                ans[rc][cc] = num++;
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