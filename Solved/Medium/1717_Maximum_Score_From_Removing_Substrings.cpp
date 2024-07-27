class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0, temp = x;
        string p1, p2;
        if (x > y)
            p1 = "ab", p2 = "ba";
        else
            p1 = "ba", p2 = "ab", x = y, y = temp;

        score += solution(s, p1) * x + solution(s, p2) * y;

        return score;
    }

    int solution(string& s, string sub) {
        stack<char> ans;
        int c = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == sub[1] && !ans.empty() && ans.top() == sub[0]) {
                c++, ans.pop();
            } else
                ans.push(s[i]);
        }
        s = "";
        while (!ans.empty()) {
            s += ans.top();
            ans.pop();
        }
        reverse(s.begin(), s.end());
        return c;
    }
};