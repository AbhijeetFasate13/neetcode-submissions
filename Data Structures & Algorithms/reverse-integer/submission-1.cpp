class Solution {
public:
    int reverse(int x) {
        bool isNeg = x<0;
        if(isNeg){
            x = -x;
        }
        string num = to_string(x);
        std::reverse(begin(num),end(num));
        int result;
        try{
            result = stoi(num);
        }catch(...){
            result = 0;
        }
        return isNeg?-result:result;
    }
};
