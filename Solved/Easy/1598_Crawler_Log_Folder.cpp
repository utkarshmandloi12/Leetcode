class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c = 0, n = logs.size();
        for (int i = 0; i < n; i++) {
            if (logs[i] == "../")
                c--;
            else if (logs[i] != "./")
                c++;
            c = max(0, c);
        }

        return c;
    }
};