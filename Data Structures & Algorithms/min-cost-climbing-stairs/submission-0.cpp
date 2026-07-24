class Solution {
    int helper(int idx,const vector<int>& cost,vector<int>&dp){
        if(idx>=cost.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        return dp[idx] = cost[idx] + min(helper(idx+1,cost,dp),helper(idx+2,cost,dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(helper(0,cost,dp),helper(1,cost,dp));
    }
};
