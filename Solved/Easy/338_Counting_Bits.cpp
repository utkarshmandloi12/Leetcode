class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> a;
        for (int i = 0; i <= n; i++) {
            int c = 0, num = i;
            while (num > 0) {
                if (num % 2 == 1) {
                    c++;
                }
                num /= 2;
            }
            a.push_back(c);
        }

        return a;
    }
};