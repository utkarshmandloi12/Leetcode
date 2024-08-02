class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size(), c = 0, c0 = 0;

        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = 1;
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
                c++;
            }
        }

        if (nums[n - 1] == 0 || nums[n - 2] == 0)
            return -1;
        return c;
    }
};