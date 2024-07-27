class Solution {
public:
    int passThePillow(int n, int time) {
        int c = 0;
        while (time >= n) {
            time -= n;
            time++;
            c++;
        }

        if (c % 2)
            return n - time;
        return time + 1;
    }
};