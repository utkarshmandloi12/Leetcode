class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), c = 0, ans = 0, temp = 0;
        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            c++;
            while (mp[s[i]] > 1) {
                c--;
                mp[s[temp++]]--;
            }
            ans = max(ans, c);
        }

        return ans;
    }
};