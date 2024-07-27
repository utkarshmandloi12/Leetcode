class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n1 = rowSum.size(), n2 = colSum.size(), i = 0, j = 0;
        vector<vector<int>> ans(n1, vector<int>(n2, 0));
        // vector<int> row(n1, 0), col(n2, 0);

        while (i < n1 && j < n2) {
            ans[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];
            colSum[j] == 0 ? j++ : i++;
        }

        return ans;
    }
};