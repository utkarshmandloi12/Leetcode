class Solution
{
public:
    int minimumDeletions(string s)
    {
        int ans = INT_MAX, n = s.length();
        vector<int> ca(n + 1, 0), cb(n + 1, 0);
        int c = 0;

        for (int i = 0; i < n; i++)
        {
            cb[i] = c;
            if (s[i] == 'b')
                c++;
        }

        c = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            ca[i] = c;
            if (s[i] == 'a')
                c++;
        }

        for (int i = 0; i < n; i++)
        {
            ans = min(ans, ca[i] + cb[i]);
        }

        return ans;
    }
};