class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long lo = 0, hi = 1e16;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1 >> 1), bits = 0;
            for (long long i = 1 << x - 1; i <= mid; i <<= x)
                bits += (mid + 1) / (i + i) * i + max(0LL, (mid + 1) % (i + i) - i);
            if (bits <= k)
                lo = mid;
            else
                hi = mid - 1;
        }

        return lo;
    }
};