class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int missing = 0;
        for(const int& num:nums){
            missing ^= num;
        }
        return missing;
    }
};
