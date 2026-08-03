class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> canReach(n, false);
        canReach[0] = true;
        for (int i = 0; i < n; i++) {
            if (!canReach[i]) continue;
            for (int j = i + 1; j <= min(i + nums[i], n - 1); j++) {
                canReach[j] = true;
            }
        }

        return canReach[n - 1];
    }
};