class Solution {
public:
    int minimumLength(string s) {
        int len = 0, n = s.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[int(s[i]) - 97]++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] < 3)
                len += freq[i];
            else {
                len += freq[i] % 2 == 0 ? 2 : 1;
            }
        }

        return len;
    }
};