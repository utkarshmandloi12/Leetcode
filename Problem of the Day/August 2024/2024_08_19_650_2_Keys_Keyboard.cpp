class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        int c = 0, temp = 1, add = 0;

        while (temp < n)
        {
            if (n % temp == 0)
                add = temp, c++;
            temp += add;
            c++;
        }

        return c;
    }
};