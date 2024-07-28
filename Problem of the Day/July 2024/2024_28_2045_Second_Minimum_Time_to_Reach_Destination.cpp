class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> list(n + 1);
        vector<int> d1(n + 1, -1), d2(n + 1, -1);
        queue<pair<int, int>> q;

        for (auto i : edges)
        {
            list[i[0]].push_back(i[1]);
            list[i[1]].push_back(i[0]);
        }

        q.push({1, 1}), d1[1] = 0;

        while (!q.empty())
        {
            auto [val, freq] = q.front();
            q.pop();

            int t = (freq == 1) ? d1[val] : d2[val];

            if ((t / change) % 2)
                t = change * (t / change + 1) + time;
            else
                t += time;

            for (auto i : list[val])
            {
                if (d1[i] == -1)
                {
                    d1[i] = t;
                    q.push({i, 1});
                }
                else if (d2[i] == -1 && d1[i] != t)
                {
                    if (i == n)
                        return t;
                    d2[i] = t;
                    q.push({i, 2});
                }
            }
        }
        return 0;
    }
};