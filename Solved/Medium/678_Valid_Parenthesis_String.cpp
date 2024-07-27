class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        vector<int> ans, str;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                ans.push_back(i);
            else if (s[i] == '*')
                str.push_back(i);
            else if (s[i] == ')' && !ans.empty())
                ans.pop_back();
            else if (s[i] == ')' && !str.empty())
                str.pop_back();
            else
                return false;
        }

        while (!ans.empty() && !str.empty() && ans.back() < str.back()) {
            ans.pop_back(), str.pop_back();
        }

        if (!ans.empty())
            return false;
        return true;
    }
};