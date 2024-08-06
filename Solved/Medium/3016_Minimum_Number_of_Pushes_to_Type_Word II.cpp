class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> mp(26, 0);
        int c = 0, ans = 0, press = 1;
        for (auto i : word)
        {
            mp[int(i) - 97]++;
        }

        sort(mp.begin(), mp.end(), [&](auto a, auto b)
             { return a > b; });

        for (auto i : mp)
        {
            ans += i * press;
            c++;
            if (c % 8 == 0)
                press++;
        }

        return ans;
    }
};