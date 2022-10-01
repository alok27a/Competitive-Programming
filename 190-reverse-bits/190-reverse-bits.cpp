class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int shift = 31;
        while (n > 0) {
            result ^= ((n % 2) << shift);
            n >>= 1;
            --shift;
        }
        
        return result;
    }
};