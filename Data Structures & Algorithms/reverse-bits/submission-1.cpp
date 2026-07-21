class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string bin;
        while(n){
            bin.push_back((n&1)?'1':'0');
            n>>=1;
        }
        while(bin.size()<32){
            bin.push_back('0');
        }
        return stoul(bin,nullptr,2);
    }
};
