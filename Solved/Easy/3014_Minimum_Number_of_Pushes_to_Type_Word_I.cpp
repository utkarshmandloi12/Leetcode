class Solution
{
public:
    int minimumPushes(string word)
    {
        int ans = 0, n = word.length();
        for (int i = 0; i < n; i++)
        {
            ans += 1 + i / 8;
        }

        return ans;
    }
};