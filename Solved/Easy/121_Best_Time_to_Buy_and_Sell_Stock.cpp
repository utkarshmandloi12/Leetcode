class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximum = 0, minimum = prices[0], n = prices.size();

        for (int i = 1; i < n; i++) {
            if (prices[i] < minimum) {
                minimum = prices[i];
            }

            if (maximum < prices[i] - minimum) {
                maximum = prices[i] - minimum;
            }
        }

        return maximum;
    }
};