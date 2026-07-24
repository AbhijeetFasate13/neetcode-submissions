class Solution {
    int loot(int idx, const vector<int>& nums, vector<int>&dp){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        return dp[idx] = max(nums[idx]+loot(idx+2,nums,dp),loot(idx+1,nums,dp));
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return max(loot(0,nums,dp),loot(1,nums,dp));
    }
};
