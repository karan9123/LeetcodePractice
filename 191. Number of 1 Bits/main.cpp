#include<cstdint>


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for (int i = 31; i >= 0; --i) {
        uint32_t mask = 1 << i;
        uint32_t bit = (n & mask) >> i;
        if (bit==1){
            result ++;
        }

    }
    return result;
        
    }
};
