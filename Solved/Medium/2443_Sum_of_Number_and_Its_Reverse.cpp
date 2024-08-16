class Solution
{
public:
    bool sumOfNumberAndReverse(int num)
    {
        int len = to_string(num).length();

        for (int i = 0; i < num; i++)
        {

            string n = to_string(i);
            int nr = stoi(n);
            reverse(n.begin(), n.end());
            if (stoi(n) + nr == num)
                return true;
        }

        return false;
    }
};