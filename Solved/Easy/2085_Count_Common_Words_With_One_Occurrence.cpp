class Solution
{
public:
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        int c = 0;
        unordered_map<string, int> mp, mp2;

        for (auto i : words1)
            mp[i]++;
        for (auto i : words2)
            mp2[i]++;
        for (auto i : words1)
            if (mp[i] == 1 && mp2[i] == 1)
                c++;

        return c;
    }
};