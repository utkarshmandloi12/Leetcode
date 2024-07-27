class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(), sum = 0;
        code.insert(code.end(), code.begin(), code.end());
        vector<int> ans(n, 0);

        if (k == 0)
            return ans;

        if (k > 0) {
            for (int i = 0, j = 0; i < 2 * n - 1; i++) {
                sum += code[i + 1];
                if (i >= k - 1 && j < n) {
                    ans[j] = sum;
                    sum -= code[j + 1];
                    cout << j << " " << ans[j] << " " << sum << " \n";

                    j++;
                }
            }
            return ans;
        }
        sum = 0;
        for (int i = 2 * n - 1, j = n - 1; i > 0; i--) {
            sum += code[i - 1];
            if (i <= 2 * n + k && j >= 0) {
                ans[j] = sum;
                sum -= code[j + n - 1];
                j--;
            }
        }

        return ans;
    }
};