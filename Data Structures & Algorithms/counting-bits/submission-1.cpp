class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>bitCount(n+1);
        for(int i=1;i<=n;i++){
            bitCount[i] = bitCount[i/2]+(i&1);
        }
        return bitCount;
    }
};
