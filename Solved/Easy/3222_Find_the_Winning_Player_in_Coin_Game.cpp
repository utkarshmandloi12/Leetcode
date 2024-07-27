class Solution {
public:
    string losingPlayer(int x, int y) {
        int c = 0;
        while (x > 0 && y > 3) {
            x--;
            y -= 4;
            c++;
        }
        if (c % 2 == 0)
            return "Bob";
        return "Alice";
    }
};