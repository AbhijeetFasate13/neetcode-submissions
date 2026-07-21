class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bitCount = 0;
        while(n){
            if(n&1){
                bitCount++;
            }
            n>>=1;
        }
        return bitCount;
    }
};
