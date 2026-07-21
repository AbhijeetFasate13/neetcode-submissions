class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;
        int buy = prices[0], sell = prices[1];
        int profit = max(0, sell-buy);
        for (int i = 1; i < prices.size(); i++) {
            if(buy>prices[i]){
                buy = prices[i];
                sell = 0;
                profit = max(profit, sell - buy);
                continue;
            }
            sell = max(sell, prices[i]);
            profit = max(profit, sell - buy);
        }
        return profit;
    }
};
