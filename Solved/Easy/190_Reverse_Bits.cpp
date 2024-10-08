class Solution {
public:
    uint32_t k = 0;
    int l = 31;

    uint32_t reverseBits(uint32_t n) {
        if (n == 0)
            return 0;
        if (n & 1)
            k += 1 << l;
        l--;
        reverseBits(n >> 1);
        return k;
    }
};