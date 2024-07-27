class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int tp = 0, mx = 0, j = 0;
        vector<pair<int, int>> dp;

        for (int i = 0; i < profit.size(); i++) {
            dp.push_back({difficulty[i], profit[i]});
        }

        sort(worker.begin(), worker.end());
        sort(dp.begin(), dp.end());

        for (int i = 0; i < worker.size(); i++) {
            while (worker[i] >= dp[j].first && j < worker.size()) {
                mx = max(mx, dp[j++].second);
            }

            tp += mx;
        }

        return tp;
    }
};