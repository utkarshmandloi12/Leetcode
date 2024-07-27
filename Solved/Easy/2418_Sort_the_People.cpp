class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<string> ans(n);
        vector<int> h(n);

        for (int i = 0; i < n; i++) h[i] = i;

        sort(h.begin(), h.end(), [&](int a, int b) { return heights[a] > heights[b]; });

        for (int i = 0; i < n; i++) {
            ans[i] = names[h[i]];
        }

        return ans;
    }
};