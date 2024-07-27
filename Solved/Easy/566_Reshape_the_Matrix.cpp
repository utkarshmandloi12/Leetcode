class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<int> a;
        int row = mat.size(), column = mat[0].size(), idx = 0;
        vector<vector<int>> b(r, vector<int>(c));

        if ((row * column != r * c) || row == r && column == c)
            return mat;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                a.push_back(mat[i][j]);
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                b[i][j] = a[idx++];
            }
        }

        return b;
    }
};
