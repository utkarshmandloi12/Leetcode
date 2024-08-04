class Solution
{
public:
    int winningPlayerCount(int n, vector<vector<int>> &pick)
    {
        int c = 0, temp = 1;
        vector<int> freq(n, 0);
        sort(pick.begin(), pick.end(), [&](auto a, auto b)
             {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0]; });

        for (int i = 0; i < pick.size(); i++)
        {
            if (i < pick.size() - 1 && pick[i][0] == pick[i + 1][0] && pick[i][1] == pick[i + 1][1])
                temp++;
            else
                temp = 1;
            if (temp > pick[i][0] && freq[pick[i][0]] == 0)
            {
                c++;
                freq[pick[i][0]] = 1;
            };
        }

        return c;
    }
};