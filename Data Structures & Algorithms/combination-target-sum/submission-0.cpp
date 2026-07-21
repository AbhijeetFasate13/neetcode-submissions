class Solution {
    void rec(int idx,int n,const vector<int>& nums,
    vector<int>&container, int target, vector<vector<int>>&ans){
        if(idx==n){
            if(0==target){
                ans.push_back(container);
            }
            return;
        }
        if(target>0){
        container.push_back(nums[idx]);
        rec(idx,n,nums,container,target-nums[idx],ans);
        container.pop_back();
        }
        rec(idx+1,n,nums,container,target,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>container;
        rec(0,(int)nums.size(),nums,container,target,ans);
        return ans;
    }
};
