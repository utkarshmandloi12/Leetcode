class Solution {
public:
    int maxBottlesDrunk(int n, int e) {
        int c = n;
        int empty = n;
        while (empty >= e) {
            c++;
            empty = empty - e + 1;
            e++;
        }
        cout << e << " ";
        return c;
    }
};