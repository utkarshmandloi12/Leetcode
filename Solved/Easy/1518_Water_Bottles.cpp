class Solution {
public:
    int numWaterBottles(int n, int e) {
        int c = n;
        int empty = n;
        while (empty >= e) {
            c += empty / e;
            empty = empty / e + empty % e;
        }

        return c;
    }
};