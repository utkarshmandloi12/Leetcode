class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int ans = 0;
        int n = s.size();
        int i = 1;
        while (i < n) {
            if (abs(s[i] - s[i - 1]) == 1 || s[i] == s[i - 1]) {
                ans++;
                i = i + 2;
                continue;
            }
            i++;
        }

        return ans;
    }
};