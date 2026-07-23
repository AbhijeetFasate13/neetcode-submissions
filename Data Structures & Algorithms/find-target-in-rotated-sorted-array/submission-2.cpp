class Solution {
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    int binarySearch(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }

   public:
    int search(vector<int>& nums, int target) {
        int pivot = findMin(nums);
        int ans = binarySearch(nums, target, pivot, nums.size() - 1);
        if(ans==-1)ans = binarySearch(nums, target, 0, pivot - 1);
        return ans == -1 ? -1 : ans;
    }
};
