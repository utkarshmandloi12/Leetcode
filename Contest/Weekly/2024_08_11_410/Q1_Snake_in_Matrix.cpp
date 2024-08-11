class Solution
{
public:
    int finalPositionOfSnake(int n, vector<string> &commands)
    {

        int r = 0, d = 0;

        for (auto i : commands)
        {
            if (i == "UP")
                d--;
            if (i == "DOWN")
                d++;
            if (i == "RIGHT")
                r++;
            if (i == "LEFT")
                r--;
        }

        return (n * d + r);
    }
};