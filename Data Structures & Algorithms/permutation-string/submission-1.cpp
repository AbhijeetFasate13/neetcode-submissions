class Solution {
    bool checkFreqArr(vector<int>&a, vector<int>&b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>source(26), destination(26);
        int k = s1.size();
        for(int i=0;i<k;i++)source[s1[i]-'a']++;
        int l = 0;
        int n = s2.size();
        if(k>n)return false;
        for(int r=0;r<k;r++){
            destination[s2[r]-'a']++;
        }
        if(checkFreqArr(source,destination))return true;
        for(int r=k;r<n;r++){
            destination[s2[r]-'a']++;
            destination[s2[l++]-'a']--;
            if(checkFreqArr(source,destination))return true;
        }
        return false;
    }
};
