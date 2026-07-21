class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>>groups = new HashMap<>();
        for(String str:strs){
            int[] charFreq = new int[26];
            for(char c:str.toCharArray()){
                charFreq[c-'a']++;
            }
            StringBuilder s = new StringBuilder();
            for(int i=0;i<26;i++){
                if(charFreq[i]==0)continue;
                s.append((char)(i+'a'));
                s.append((char)(charFreq[i]+'0'));
            }
            groups.computeIfAbsent(s.toString(),k->new ArrayList()).add(str);
        }
        return groups.values().stream().toList();
    }
}
