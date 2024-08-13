class Solution
{
    vector<int> temp;
    vector<vector<int>> ans;

public:
    vector<vector<int>> combinationSum2(vector<int> &c, int target)
    {
        sort(c.begin(), c.end());
        solution(c, c.size(), 0, target);

        return ans;
    }

    void solution(vector<int> c, int n, int id, int t)
    {
        if (t == 0)
        {
            ans.push_back(temp);
        }

        for (int i = id; i < n; i++)
        {
            if (t < c[i])
                break;
            if (i == id || c[i] != c[i - 1])
            {
                temp.push_back(c[i]);
                solution(c, n, i + 1, t - c[i]);
                temp.pop_back();
            }
        }
    }
};