class Solution
{
    vector<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> temp;
    vector<vector<int>> ans;

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        solution(k, 0, n);
        return ans;
    }

    void solution(int k, int id, int t)
    {
        if (temp.size() == k && t == 0)
        {
            ans.push_back(temp);
        }

        for (int i = id; i < 9; i++)
        {
            if (c[id] > t)
                return;
            temp.push_back(c[i]);
            solution(k, i + 1, t - c[i]);
            temp.pop_back();
        }
    }
};