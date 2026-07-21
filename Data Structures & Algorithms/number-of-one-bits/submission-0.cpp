class Solution {
public:
    int hammingWeight(uint32_t n) {
        int setBitCount = 0;
        while(n){
            setBitCount += (n&1);
            n>>=1;
        }
        return setBitCount;
    }
};
