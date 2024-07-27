class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int c1 = 0, c2 = 0, c3 = 0;
        for (int i = 2; i <= n; i++) {
            int ps = c1 + cost[i - 1];
            int pps = c2 + cost[i - 2];
            c3 = min(ps, pps);
            c2 = c1;
            c1 = c3;
        }

        return c1;
    }
};