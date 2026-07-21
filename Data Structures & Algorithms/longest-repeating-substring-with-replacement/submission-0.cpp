class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, n = s.size();
        unordered_map<char,int>mp;
        int maxF = 0;
        int ans = 0;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            maxF = max(maxF, mp[s[r]]);
            if(r-l+1-maxF>k){
                mp[s[l]]--;
                if(s[l]==s[r])maxF--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
