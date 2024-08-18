class Solution
{
public:
    int countKConstraintSubstrings(string s, int k)
    {
        int n = s.length();
        int c = n, wd = 2;

        for (int i = 0; i < n && wd <= n; i++)
        {

            int c0 = 0, c1 = 0;
            int temp = 0;

            for (int j = 0; j < n; j++)
            {
                if (s[j] == '0')
                    c0++;
                else
                    c1++;

                if (j >= wd - 1)
                {
                    if (c0 <= k || c1 <= k)
                        temp++;
                    if (s[j - wd + 1] == '0')
                        c0--;
                    else
                        c1--;
                }
            }

            c += temp;
            wd++;
        }

        return c;
    }
};