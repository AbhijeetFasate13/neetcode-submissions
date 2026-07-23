class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);

        int half = (m + n + 1) / 2;
        int l = 0, r = m;
        int aLeft, aRight, bLeft, bRight;
        while (l <= r) {
            int mid = (l + r) / 2;
            aLeft = (mid == 0) ? INT_MIN : nums1[mid - 1];
            aRight = (mid == m) ? INT_MAX : nums1[mid];
            bLeft = (half - mid == 0) ? INT_MIN : nums2[half - mid - 1];
            bRight = (half - mid == n) ? INT_MAX : nums2[half - mid];
            if (aLeft <= bRight and bLeft <= aRight) {
                if ((m + n) % 2 == 1) {
                    return max(aLeft, bLeft);
                }
                return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
            } else {
                if (aLeft > bRight) {
                    // took too many from A, reduce
                    r = mid - 1;
                } else {
                    // too too few
                    l = mid + 1;
                }
            }
        }
        return 0.0;
    }
};
