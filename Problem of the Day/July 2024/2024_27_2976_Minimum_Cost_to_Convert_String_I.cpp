class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        int n = source.size(), o = original.size();
        vector<vector<long long>> min_cost(26, vector<long long>(26, INT_MAX));

        for (int i = 0; i < o; i++) {
            min_cost[original[i] - 'a'][changed[i] - 'a'] =
                min(min_cost[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
        }
        calcMin(min_cost);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (source[i] != target[i]) {
                if (min_cost[source[i] - 'a'][target[i] - 'a'] >= INT_MAX)
                    return -1;
                ans += min_cost[source[i] - 'a'][target[i] - 'a'];
            }
        }

        return ans;
    }

    void calcMin(vector<vector<long long>>& g) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    g[j][k] = min(g[j][k], g[i][k] + g[j][i]);
                }
            }
        }
    }
};