class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> idx;
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                idx.push(i);
            else if (s[i] == ')') {
                int begin = idx.top();
                idx.pop();
                reverse(s.begin() + begin, s.begin() + i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] != '(' && s[i] != ')')
                ans += s[i];
        }

        return ans;
    }
};