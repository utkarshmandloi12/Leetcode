class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int c5 = 0, c10 = 0;
        for (auto i : bills)
        {
            if (i == 5)
                c5++;
            if (i == 10)
                c5--, c10++;
            if (i == 20)
            {
                if (c10 > 0)
                    c10--, c5--;
                else
                    c5 -= 3;
            }

            if (c5 < 0)
                return false;
        }
        return true;
    }
};