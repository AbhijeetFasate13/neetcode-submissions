class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>>groups = new HashMap<>();
        for(String str:strs){
            char[] strArr = str.toCharArray();
            Arrays.sort(strArr);
            groups.computeIfAbsent(new String(strArr),k->new ArrayList()).add(str);
        }
        return groups.values().stream().toList();
    }
}
