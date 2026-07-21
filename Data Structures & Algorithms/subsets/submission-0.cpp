class Solution {
    void rec(int idx, int n, const vector<int>& nums, vector<int>&container, vector<vector<int>>&ans){
        if(idx==n){
            ans.push_back(container);
            return;
        }
        container.push_back(nums[idx]);
        rec(idx+1,n,nums,container,ans);
        container.pop_back();
        rec(idx+1,n,nums,container,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>container;
        rec(0,(int)nums.size(),nums,container,ans);
        return ans;
    }
};
