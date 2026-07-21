class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int[] freq = new int[2001];
        for (int num : nums) {
            freq[num + 1000]++;
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> b[0] - a[0]
        );
        for (int i = 0; i < 2001; i++) {
            if (freq[i] > 0) {
                pq.add(new int[]{freq[i], i - 1000});
            }
        }
        
        int[] ans = new int[k];
        for (int i = 0; i < k; i++) {
            ans[i] = pq.poll()[1];
        }
        
        return ans;
    }
}
