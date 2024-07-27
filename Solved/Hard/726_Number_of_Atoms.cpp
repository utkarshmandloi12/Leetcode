class Solution {
public:
    string countOfAtoms(string a) {
        int n = a.size();
        stack<unordered_map<string, int>> count;
        string res;
        count.push(unordered_map<string, int>());
        for (int i = 0; i < n; i++) {
            if (a[i] == '(') {
                count.push(unordered_map<string, int>());
            } else if (a[i] == ')') {
                unordered_map<string, int> br = count.top();
                count.pop();
                string mul;
                int idx = i + 1;
                while (idx < n && isdigit(a[idx])) {
                    mul += a[idx++];
                }
                if (!mul.empty()) {
                    int m = stoi(mul);
                    for (auto [el, c] : br) {
                        br[el] = c * m;
                    }
                }
                for (auto [el, c] : br) {
                    count.top()[el] += c;
                }
                i = idx - 1;
            } else {
                string element, freq;
                int idx = i;
                element += a[i];
                i++;
                while (i < n && islower(a[i])) {
                    element += a[i];
                    i++;
                }
                while (i < n && isdigit(a[i])) {
                    freq += a[i];
                    i++;
                }
                int c = freq.empty() ? 1 : stoi(freq);
                count.top()[element] += c;
                i--;
            }
        }

        map<string, int> ans(count.top().begin(), count.top().end());

        for (auto [el, c] : ans) {
            res += el;
            if (c > 1)
                res += to_string(c);
        }

        return res;
    }
};