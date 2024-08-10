class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '1')
                {
                    cnt++;
                    rem(grid, i, j, r, c);
                }
            }
        }

        return cnt;
    }

    void rem(vector<vector<char>> &grid, int i, int j, int r, int c)
    {
        grid[i][j] = '0';
        if (i > 0 && grid[i - 1][j] == '1')
            rem(grid, i - 1, j, r, c);
        if (j > 0 && grid[i][j - 1] == '1')
            rem(grid, i, j - 1, r, c);
        if (i < r - 1 && grid[i + 1][j] == '1')
            rem(grid, i + 1, j, r, c);
        if (j < c - 1 && grid[i][j + 1] == '1')
            rem(grid, i, j + 1, r, c);
    }
};