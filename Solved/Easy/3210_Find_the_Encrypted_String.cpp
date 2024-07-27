class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.length();
        string ans = "";

        while (k >= n) k -= n;

        for (int i = k; i < n; i++) {
            ans += s[i];
        }
        for (int i = 0; i < k; i++) {
            ans += s[i];
        }

        return ans;
    }
};