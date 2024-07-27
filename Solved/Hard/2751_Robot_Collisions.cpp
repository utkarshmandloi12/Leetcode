// class Solution {
// public:
//     vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths,
//     string directions) {
//         int n = positions.size();
//         vector<pair<int, int>> ph(n), pd(n), hd(n);
//         for(int i = 0; i < positions.size(); i++){
//             pd[i].first = ph[i].first = positions[i];
//             ph[i].second = healths[i];
//             pd[i].second = directions[i] == 'R' ? 1 : 0;
//         }

//         sort(ph.begin(), ph.end());
//         sort(pd.begin(), pd.end());

//         for(int i = 0; i < n; i++){
//             hd[i].first = ph[i].second;
//             hd[i].second = pd[i].second;
//         }

//         return healths;
//     }
// };
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths,
                                      string directions) {
        int n = positions.size();
        vector<int> ans, idx(n);
        stack<int> pos;

        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }

        sort(idx.begin(), idx.end(),
             [&](int i, int j) { return positions[i] < positions[j]; });

        for (int i = 0; i < n; i++) {
            if (directions[idx[i]] == 'R')
                pos.push(idx[i]);
            else {
                while (!pos.empty() && healths[idx[i]] > 0) {
                    int top = pos.top();
                    pos.pop();
                    if (healths[idx[i]] > healths[top]) {
                        healths[idx[i]]--;
                        healths[top] = 0;
                    } else if (healths[idx[i]] < healths[top]) {
                        healths[idx[i]] = 0;
                        healths[top]--;
                        pos.push(top);
                    } else {
                        healths[idx[i]] = healths[top] = 0;
                    }
                }
            }
        }

        for (auto i : healths) {
            if (i > 0)
                ans.push_back(i);
        }

        return ans;
    }
};