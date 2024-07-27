class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int i, c1 = 0, c2 = 0;
        int r = red, b = blue;

        for (i = 1;; i++) {
            if (i % 2 == 0 && r >= i)
                r -= i;
            else if (i % 2 == 1 && b >= i)
                b -= i;
            else
                break;
            c1++;
        }
        for (i = 1;; i++) {
            if (i % 2 == 0 && blue >= i)
                blue -= i;
            else if (i % 2 == 1 && red >= i)
                red -= i;
            else
                break;
            c2++;
        }
        return max(c1, c2);
    }
};