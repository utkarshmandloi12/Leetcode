class Solution
{
public:
    int nonSpecialCount(int l, int r)
    {

        int ans = 0;
        vector<int> prime(1e5, 1);

        for (long long i = 2; i < 1e5; i++)
        {
            if (prime[i])
            {
                if (l <= i * i && i * i <= r)
                    ans++;
                for (long long j = i * i; j < 1e5; j += i)
                    prime[j] = 0;
            }
        }

        return r - l - ans + 1;
    }
};