class Solution {
    void rec(int i, vector<int>&nums,vector<int>&curr, vector<int>&visited, vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(!visited[j]){
                visited[j] = 1;
                curr.push_back(nums[j]);
                rec(i+1,nums,curr,visited,ans);
                visited[j] = 0;
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>visited(n),curr;
        vector<vector<int>>ans;
        rec(0,nums,curr,visited,ans);
        return ans;
    }
};
