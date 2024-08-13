class Solution
{
    vector<int> temp;
    vector<vector<int>> ans;

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        solution(candidates, candidates.size(), 0, target);

        return ans;
    }

    void solution(vector<int> c, int n, int id, int t)
    {
        if (t == 0)
        {
            ans.push_back(temp);
        }

        if (id >= n || c[id] > t)
            return;

        for (int i = id; i < n; i++)
        {
            temp.push_back(c[i]);
            solution(c, n, i, t - c[i]);
            temp.pop_back();
        }
    }
};