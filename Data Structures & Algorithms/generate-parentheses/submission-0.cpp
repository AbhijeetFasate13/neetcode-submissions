class Solution {
    void rec(int open, int close, int n, string& curr, vector<string>&ans){
        if(curr.size()==2*n){
            if(open==close)ans.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            rec(open+1,close,n,curr,ans);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            rec(open,close+1,n,curr,ans);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string>ans;
        rec(0,0,n,curr,ans);
        return ans;
    }
};
