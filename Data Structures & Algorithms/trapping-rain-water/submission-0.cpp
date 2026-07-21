class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int leftMax = height[l], rightMax = height[r];
        int ans = 0;
        while(l<r){
            if(height[l]<height[r]){
                if(leftMax<=height[l])leftMax=height[l];
                else ans += leftMax-height[l];
                l++;
            }else{
                if(rightMax<=height[r])rightMax=height[r];
                else ans += rightMax-height[r];
                r--;
            }
        }
        return ans;
    }
};
