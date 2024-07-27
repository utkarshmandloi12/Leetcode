class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& a) {
        int n = a.size();
        int c = 0;

        for (int i = 0; i < n - 2; i++) {
            if (a[i] != a[i + 1] && a[i] == a[i + 2])
                c++;
        }
        if (a[0] != a[n - 1] && a[n - 1] == a[1])
            c++;
        if (a[0] == a[n - 2] && a[n - 1] != a[0])
            c++;

        return c;
    }
};