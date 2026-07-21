class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        for(const int& num:nums){
            missing ^= num;
        }
        for(int i=0;i<=nums.size();i++){
            missing ^= i;
        }
        return missing;
    }
};
