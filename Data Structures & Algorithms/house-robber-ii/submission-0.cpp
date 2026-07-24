class Solution {
    int loot(int start, int end, const vector<int>& nums, vector<int>& dp) {
        if (start > end) return 0;
        if (dp[start] != -1) return dp[start];

        return dp[start] = max(
            nums[start] + loot(start + 2, end, nums, dp),
            loot(start + 1, end, nums, dp)
        );
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 = loot(0, n - 2, nums, dp1);
        int case2 = loot(1, n - 1, nums, dp2);

        return max(case1, case2);
    }
};
