class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int w)
    {
        int n = books.size();
        vector<int> ans(n + 1, 0);
        ans[0] = 0, ans[1] = books[0][1];

        for (int i = 1; i <= n; i++)
        {
            int remain = w - books[i - 1][0];
            int height = books[i - 1][1];

            ans[i] = ans[i - 1] + height;

            int j = i - 1;

            while (j > 0 && remain - books[j - 1][0] >= 0)
            {
                remain -= books[j - 1][0];
                height = max(height, books[j - 1][1]);
                ans[i] = min(ans[i], ans[j - 1] + height);
                j--;
            }
        }

        return ans[n];
    }
};