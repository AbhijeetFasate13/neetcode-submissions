class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int missing = 0;
        for(const int& i:nums){
            missing ^= i;
        }
        return missing;
    }
};
