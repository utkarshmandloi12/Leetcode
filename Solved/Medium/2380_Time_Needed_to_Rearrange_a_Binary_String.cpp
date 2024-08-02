class Solution
{
public:
    int secondsToRemoveOccurrences(string s)
    {
        int n = s.length(), i0 = 0, c = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                i0++;
            if (s[i] == '1' && i0 > 0)
                c = max(c + 1, i0);
        }

        return c;
    }
};