class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer>mp = new HashMap<>();
        int n = nums.length,num;
        for(int i=0;i<n;i++){
            num = nums[i];
            if(mp.containsKey(target-num))return new int[] {mp.get(target-num),i};
            mp.put(num,i);
        }
        return new int[]{};
    }
}
