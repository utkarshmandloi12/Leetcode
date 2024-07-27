class Solution {
public:
    int hammingWeight(int n) {
        int i = 0, c = 0;
        while (n > 0) {
            if (n % 2)
                c++;
            n /= 2;
        }
        return c;
    }
};