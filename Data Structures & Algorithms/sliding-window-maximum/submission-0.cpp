class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>d;
        int n = nums.size();
        vector<int>ans(n-k+1);
        for(int i=0;i<n;i++){
            while(!d.empty() and d.front() <= i-k){
                d.pop_front();
            }
            while(!d.empty() and nums[d.back()] <= nums[i]){
                d.pop_back();
            }
            d.push_back(i);
            if(i-k+1>=0){
                ans[i-k+1] = nums[d.front()];
            }
        }
        return ans;
    }
};
