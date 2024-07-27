class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9 + 7));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (auto i : edges) {
            int s = i[0], e = i[1];
            dist[s][e] = i[2];
            dist[e][s] = i[2];
        }

        floyd(n, dist);

        return calcAns(n, dist, d);
    }

    void floyd(int n, vector<vector<int>>& dist) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }
    }

    int calcAns(int n, vector<vector<int>>& dist, int t) {
        int ans = 0, count = n;
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= t)
                    c++;
            }
            if (c <= count) {
                count = c;
                ans = i;
            }
        }

        return ans;
    }
};