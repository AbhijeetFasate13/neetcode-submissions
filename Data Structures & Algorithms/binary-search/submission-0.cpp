class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while(l+1<r){
            int m = l + (r-l)/2;
            if(nums[m]<=target){
                l = m;
            }else{
                r = m;
            }
        }
        if(l>-1 and l<nums.size() and nums[l]==target)return l;
        return -1;
    }
};
