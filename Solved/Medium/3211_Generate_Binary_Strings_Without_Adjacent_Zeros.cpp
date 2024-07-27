class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> s;
        string t;
        generate(s, t, n, -1);
        return s;
    }

    void generate(vector<string>& s, string& t, int n, int l) {
        if (t.length() == n) {
            s.push_back(t);
            return;
        }

        t += '1';
        generate(s, t, n, 1);
        t.pop_back();

        if (l != 0) {
            t += '0';
            generate(s, t, n, 0);
            t.pop_back();
        }
    }
};