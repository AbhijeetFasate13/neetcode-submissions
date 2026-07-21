class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length(), m = t.length();
        if(n!=m)return false;
        int[] charFreq = new int[26];
        for(int i=0;i<n;i++){
            charFreq[s.charAt(i)-'a']++;
            charFreq[t.charAt(i)-'a']--;
        }
        for(int i:charFreq){
            if(i!=0)return false;
        }
        return true;
    }
}
