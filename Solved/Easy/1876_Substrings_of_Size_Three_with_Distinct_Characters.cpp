class Solution {
public:
    int countGoodSubstrings(string s) {
        int c = 0, n = s.size();

        for (int i = 0; i <= n - 3; i++) {
            c++;
            if (s[i] == s[i + 1] || s[i] == s[i + 2] || s[i + 1] == s[i + 2])
                c--;
        }

        return c;
    }
};