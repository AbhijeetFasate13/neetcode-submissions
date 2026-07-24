class Solution {
    vector<vector<int>>dp;
    int rec(int i, vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        if (i == coins.size())
            return INT_MAX / 10;
        if(dp[i][amount]!=-1)return dp[i][amount];
        if (coins[i] <= amount) {
            return dp[i][amount] = min(
                1 + rec(i, coins, amount - coins[i]),
                rec(i + 1, coins, amount)
            );
        }

        return dp[i][amount] = rec(i + 1, coins, amount);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size()+1,vector<int>(amount+1,-1));
        int ans = rec(0, coins, amount);
        return ans >= INT_MAX / 10 ? -1 : ans;
    }
};