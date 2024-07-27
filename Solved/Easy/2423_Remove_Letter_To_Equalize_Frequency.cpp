class Solution {
public:
    bool equalFrequency(string s) {
        int n = s.length();
        sort(s.begin(), s.end());
        vector<int> f;
        int sz = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != s[i + 1])
                f.push_back(count(s.begin(), s.end(), s[i])), sz++;
        }

        sort(f.begin(), f.end());
        if (f[0] == 1 && f[1] > 1)
            f[0]--;
        else
            f[sz - 1]--;

        for (int i = 0; i < sz - 1; i++) {
            if (f[i] != f[i + 1] && f[i + 1] > 0 && f[i] > 0)
                return false;
        }
        return true;
    }
};