class Solution
{
public:
    int smallestValue(int n)
    {
        if (n <= 3)
            return n;

        while (!isPrime(n))
        {
            int sum = 0, num = n;

            for (int i = 2; num >= 2; i++)
            {
                if (num % i == 0)
                {
                    num /= i;
                    sum += i;
                    i--;
                }
            }

            if (sum == n)
                return n;
            n = sum;
        }

        return n;
    }

    bool isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }
};