class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c)
    {
        vector<vector<int>> ans, dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int cnt = 1, d = 0;

        while (ans.size() < rows * cols)
        {

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < cnt; j++)
                {
                    if (r >= 0 && r < rows && c >= 0 && c < cols)
                        ans.push_back({r, c});
                    r += dir[d][0];
                    c += dir[d][1];
                }
                d = (d + 1) % 4;
            }

            cnt++;
        }

        return ans;
    }
};