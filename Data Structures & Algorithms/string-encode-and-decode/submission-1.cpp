class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(const string& str:strs)encoded+= str + "[]";
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string>strs;
        string curr;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(i+1<n and s[i]=='[' and s[i+1]==']'){
                strs.push_back(curr);
                curr = "";
                i++;
            }else{
                curr.push_back(s[i]);
            }
        }
        return strs;
    }
};
