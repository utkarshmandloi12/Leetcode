class Solution {
public:
    int minChanges(int n, int k) {
        if (n == k)
            return 0;

        int c = 0;
        while (n > 0 && k > 0) {
            if (n % 2 == 1 && k % 2 == 0)
                c++;
            else if (n % 2 == 0 && k % 2 == 1)
                return -1;
            n /= 2, k /= 2;
        }
        while (n > 0) {
            if (n % 2 == 1)
                c++;
            n /= 2;
        }
        while (k > 0) {
            if (k % 2 == 1)
                return -1;
            k /= 2;
        }

        return c;
    }
};