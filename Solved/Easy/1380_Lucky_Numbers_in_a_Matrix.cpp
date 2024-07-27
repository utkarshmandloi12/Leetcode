class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans, cols, rows;

        for (int i = 0; i < n; i++) {
            int mn = matrix[i][0];
            for (int j = 0; j < m; j++) {
                mn = min(mn, matrix[i][j]);
            }
            rows.push_back(mn);
        }

        for (int i = 0; i < m; i++) {
            int mx = INT_MIN;
            for (int j = 0; j < n; j++) mx = max(mx, matrix[j][i]);
            cols.push_back(mx);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == rows[i] && matrix[i][j] == cols[j])
                    ans.push_back(matrix[i][j]);
            }
        }

        return ans;
    }
};