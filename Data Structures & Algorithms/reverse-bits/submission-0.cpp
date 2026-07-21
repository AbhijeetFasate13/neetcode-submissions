class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string binaryNum;
        while(n){
            binaryNum.push_back((n&1)?'1':'0');
            n>>=1;
        }
        while(binaryNum.size()<32){
            binaryNum.push_back('0');
        }
        uint32_t result;
        try{
            result = stoul(binaryNum,nullptr,2);
        }catch(...){
            result = 0;
        }
        return result;
    }
};
