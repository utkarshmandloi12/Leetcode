class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int start = -1;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ' || i == s.length() - 1) {
                int j = (i == s.length() - 1 ? i : i - 1);
                for (; j > start; j--) {
                    ans += s[j];
                }
                start = i;
                if (s[i] == ' ')
                    ans += ' ';
            }
        }
        return ans;
    }
};