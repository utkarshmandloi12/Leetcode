class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int n = c.size();
        double cnt = 1, sum = c[0][1], time = c[0][0] + c[0][1];
        for (int i = 1; i < c.size(); i++) {
            int wt = 0;
            if (time - c[i][0] > 0)
                wt = time - c[i][0];
            sum += c[i][1] + wt;
            time = time > c[i][0] ? time : c[i][0];
            time += c[i][1];
        }
        return sum / n;
    }
};