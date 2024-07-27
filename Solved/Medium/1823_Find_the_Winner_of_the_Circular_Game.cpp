class Solution {
public:
    int findTheWinner(int n, int k) {
        int a[n], c = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        };
        int i = 0, temp = 0;
        while (c < n) {
            if (a[i] != 0)
                temp++, ans = a[i];
            if (temp == k)
                a[i] = 0, c++, temp = 0;
            i++;
            if (i == n)
                i = 0;
        }

        return ans;
    }
};