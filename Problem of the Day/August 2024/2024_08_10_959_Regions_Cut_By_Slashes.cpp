class Solution
{
public:
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        vector<vector<char>> g(n * 3, vector<char>(n * 3, '0'));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int r = i * 3, c = j * 3;

                if (grid[i][j] == '/')
                {
                    g[r][c + 2] = '1';
                    g[r + 1][c + 1] = '1';
                    g[r + 2][c] = '1';
                }
                else if (grid[i][j] == '\\')
                {
                    g[r][c] = '1';
                    g[r + 1][c + 1] = '1';
                    g[r + 2][c + 2] = '1';
                }
            }
        }

        int c = 0;

        for (int i = 0; i < n * 3; i++)
        {
            for (int j = 0; j < n * 3; j++)
            {
                if (g[i][j] == '0')
                {
                    c++;
                    fill(g, i, j, n * 3);
                }
            }
        }

        return c;
    }

    void fill(vector<vector<char>> &g, int i, int j, int n)
    {
        queue<pair<int, int>> q;
        g[i][j] = '1';
        q.push({i, j});

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            if (r > 0 && g[r - 1][c] == '0')
                g[r - 1][c] = '1', q.push({r - 1, c});
            if (c > 0 && g[r][c - 1] == '0')
                g[r][c - 1] = '1', q.push({r, c - 1});
            if (r < n - 1 && g[r + 1][c] == '0')
                g[r + 1][c] = '1', q.push({r + 1, c});
            if (c < n - 1 && g[r][c + 1] == '0')
                g[r][c + 1] = '1', q.push({r, c + 1});
        }
    }
};