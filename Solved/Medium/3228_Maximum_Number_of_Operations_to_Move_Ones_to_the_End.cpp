class Solution {
public:
    int maxOperations(string s) {
        int c1 = 0, id = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (i - 1 >= 0 && s[i] == '0' && s[i - 1] == '1') {
                id++;
            } else if (s[i] == '1') {
                c1 += id;
            }
        }

        return c1;
    }
};