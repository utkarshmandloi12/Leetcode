class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> count(n + 2, 0);

        for (auto i : edges) {
            count[i[0]]++;
            count[i[1]]++;
            if (count[i[0]] == n)
                return i[0];
            if (count[i[1]] == n)
                return i[1];
        }

        return 0;
    }
};