class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r,
                                    vector<vector<int>>& c) {
        int n1 = r.size(), n2 = c.size();
        vector<vector<int>> ans(k, vector<int>(k, 0));
        vector<int> rp = sortele(r, k), cp = sortele(c, k);

        if (rp.empty() || cp.empty())
            return {};

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (rp[i] == cp[j])
                    ans[i][j] = rp[i];
            }
        }
        return ans;
    }

    vector<int> sortele(vector<vector<int>>& a, int n) {
        vector<vector<int>> ans(n + 1);
        vector<int> d(n + 1), seq;

        for (auto i : a) {
            ans[i[0]].push_back(i[1]);
            d[i[1]]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (d[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int f = q.front();
            q.pop();
            seq.push_back(f);
            n--;
            for (auto i : ans[f]) {
                if (--d[i] == 0)
                    q.push(i);
            }
        }

        if (n != 0)
            return {};
        return seq;
    }
};