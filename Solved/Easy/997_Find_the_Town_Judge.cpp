class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> a(n, 0);
        for (int i = 0; i < trust.size(); i++) {
            // if(trust[i][1] != trust[i-1][1]) return -1;
            a[trust[i][1] - 1]++;
            a[trust[i][0] - 1] = n - 2 * n - 1;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == n - 1)
                return i + 1;
        }
        return -1;
    }
};