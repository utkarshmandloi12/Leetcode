class Solution {
public:
    long long maximumPoints(vector<int>& e, long long int ce) {
        long int n = e.size(), points = 0;

        sort(e.begin(), e.end());

        if (e[0] > ce)
            return 0;

        for (int i = 1; i < n; i++) {
            // while(ce >= e[0]) ce-=e[0], points++;
            points += ce / e[0];
            ce = ce % e[0];
            ce += e[i];
        }

        points += ce / e[0];

        return points;
    }
};