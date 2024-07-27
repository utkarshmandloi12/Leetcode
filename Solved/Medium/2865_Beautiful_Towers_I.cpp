class Solution {
public:
    long long maximumSumOfHeights(vector<int>& a) {
        long long sum = 0, ans = 0, n = a.size();
        int idx = 0;
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            b[i] = a[i];
        }

        for (int j = 0; j < n; j++) {
            sum = a[j];

            for (int i = j; i > 0; i--) {
                if (a[i] < a[i - 1])
                    a[i - 1] = a[i];
                sum += a[i - 1];
                a[i] = b[i];
            }
            for (int i = j; i < n - 1; i++) {
                if (a[i] < a[i + 1])
                    a[i + 1] = a[i];
                sum += a[i + 1];
                a[i] = b[i];
            }

            a[0] = b[0], a[n - 1] = b[n - 1];

            if (ans < sum)
                ans = sum;
        }

        return ans;
    }
};