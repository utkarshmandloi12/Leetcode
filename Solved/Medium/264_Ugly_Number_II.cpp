class Solution
{
public:
    int nthUglyNumber(int n)
    {
        set<long> ugly;
        ugly.insert(1);
        long num = 1, i = 0;
        while (i < n)
        {
            num = *ugly.begin();
            ugly.erase(num);
            ugly.insert(num * 2);
            ugly.insert(num * 3);
            ugly.insert(num * 5);
            i++;
        }

        return num;
    }
};