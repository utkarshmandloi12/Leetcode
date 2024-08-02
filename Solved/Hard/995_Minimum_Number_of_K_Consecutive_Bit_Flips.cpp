class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int n = nums.size(), c = 0, temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (i >= k && nums[i - k] == 2)
            {
                temp--;
            }

            if ((temp % 2) == nums[i])
            {
                if (i + k > n)
                    return -1;
                nums[i] = 2;
                temp++, c++;
            }
        }

        return c;
    }
};