class Solution {
    void rec(int idx, int n, const vector<int>& nums, vector<int>& container, int target,
             vector<vector<int>>& ans) {
        if (0 == target) {
            ans.push_back(container);
            return;
        }
        for (int j = idx; j < n; j++) {
            if (j > idx and nums[j] == nums[j - 1]) continue;
            if (target - nums[j] >= 0) {
                container.push_back(nums[j]);
                rec(j + 1, n, nums, container, target - nums[j], ans);
                container.pop_back();
            } else {
                break;
            }
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        vector<int> container;
        rec(0, (int)nums.size(), nums, container, target, ans);
        return ans;
    }
};
