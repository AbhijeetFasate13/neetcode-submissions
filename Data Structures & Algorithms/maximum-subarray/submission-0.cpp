class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = -10001, maxSum = -10001;
        for(const int& i:nums){
            sum = max(i, sum+i);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};
