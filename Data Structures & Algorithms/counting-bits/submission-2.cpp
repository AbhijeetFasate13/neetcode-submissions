class Solution {
public:
    vector<int> countBits(int n) {
        int bitCount  = 0;
        vector<int> sol;
        for(int i = 0; i <=n ; i++){
            bitCount = 0;
            int temp = i;
            while(i){
                if(i&1==1){
                    bitCount += 1;
                }
                i>>=1;
            }
            i = temp;
            sol.push_back(bitCount);
        }
        return sol;
        
    }
};
