class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k = 0;
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            for (int j = k; j < t.length(); j++) {
                if (s[i] == t[j]) {
                    str += t[j];
                    k = j + 1;
                    break;
                }
            }
        }

        return (str == s);
    }
};