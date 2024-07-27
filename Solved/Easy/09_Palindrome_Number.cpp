class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 9) {
            return true;
        }
        int n = x, c = 0;
        while (n > 0) {
            c++;
            n /= 10;
        }

        int a[c], b[c];

        for (int i = 0, j = c - 1; i < c; i++, j--) {
            a[i] = x % 10;
            b[j] = x % 10;
            x /= 10;
        }

        for (int i = 0; i < c; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
};