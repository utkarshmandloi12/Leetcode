class Solution
{
public:
    int minimumNumbers(int num, int k)
    {
        if (num == 0)
            return 0;
        if (num % 10 == k)
            return 1;
        if ((num - k) % 10 == k)
            return 2;
        if (k == 0)
            return -1;
        else
        {
            int c = 1;
            while (num % 10 != k)
            {
                num -= k, c++;
                if (num < 0)
                    return -1;
            }
            return c;
        }
        return -1;
    }
};