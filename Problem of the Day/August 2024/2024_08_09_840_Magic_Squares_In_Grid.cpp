xclass Solution{
    public :
        int numMagicSquaresInside(vector<vector<int>> & grid){

            int n = grid.size(), m = grid[0].size();
int c = 0;
if (n < 3 || m < 3)
    return 0;

for (int i = 0; i < n - 2; i++)
{
    for (int j = 0; j < m - 2; j++)
    {
        if (check(grid, i, j))
            c++;
    }
}

return c;
}

bool check(vector<vector<int>> &g, int r, int c)
{
    int idr = 0, idc = 0, d1 = 0, d2 = 0;
    vector<int> row(3, 0), col(3, 0), freq(9, 0);

    for (int i = r; i < r + 3; i++)
    {
        idc = 0;
        for (int j = c; j < c + 3; j++)
        {
            if (g[i][j] > 9 || g[i][j] == 0)
                return false;
            if ((i == r && j == c) || (i == r + 1 && j == c + 1) || (i == r + 2 && j == c + 2))
                d1 += g[i][j];
            if ((i == r && j == c + 2) || (i == r + 1 && j == c + 1) || (i == r + 2 && j == c))
                d2 += g[i][j];
            row[idr] += g[i][j];
            col[idc++] += g[i][j];
            freq[g[i][j] - 1]++;
        }
        idr++;
    }

    if (d1 != d2)
        return false;

    for (int i = 0; i < 9; i++)
        if (freq[i] != 1)
            return false;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (row[i] != row[j] || row[i] != col[j] || col[i] != col[j])
                return false;
        }
    }

    return true;
}
}
;