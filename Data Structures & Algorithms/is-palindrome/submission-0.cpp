class Solution {
public:
    bool isPalindrome(string s) {
        string clean;
        for(auto& i:s){
            if(isalnum(i)){
                clean.push_back(tolower(i));
            }
        }
        int si = 0, e = clean.size()-1;
        while(si<e){
            if(clean[si]!=clean[e]){
                return false;
            }
            si++;
            e--;
        }
        return true;
    }
};
