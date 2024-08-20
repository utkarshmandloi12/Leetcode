class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<int> ss = piles;
        vector<vector<int>> store(n, vector<int>(n));

        for (int i = n - 2; i >= 0; i--)
        {
            ss[i] += ss[i + 1];
        }

        return solution(ss, 1, 0, store);
    }

    int solution(vector<int> &ss, int mx, int idx, vector<vector<int>> &store)
    {
        if (idx + 2 * mx >= ss.size())
            return ss[idx];
        if (store[idx][mx] > 0)
            return store[idx][mx];

        int ans = INT_MAX;

        for (int i = 1; i <= 2 * mx; i++)
        {
            ans = min(ans, solution(ss, max(i, mx), idx + i, store));
        }

        store[idx][mx] = ss[idx] - ans;
        return store[idx][mx];
    }
};