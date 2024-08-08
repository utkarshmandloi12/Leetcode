class Solution
{
public:
    int divide(int dd, int dr)
    {
        int ans = 0;
        if ((dd == INT_MIN && dr == -1))
            return INT_MAX;
        if ((dd == INT_MIN && dr == 1))
            return INT_MIN;

        long int d = abs(dd), dv = abs(dr);
        while (d >= dv)
        {
            long int temp = dv, c = 1;
            while (d - temp >= temp)
            {
                temp += temp;
                c += c;
            }
            ans += c;
            d -= temp;
        }

        if ((dd < 0 && dr > 0) || dd > 0 && dr < 0)
            return -ans;
        return ans;
    }
};