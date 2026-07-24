class Solution {
    unordered_map<char,string>mp;
public:
    Solution(){
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
    }
    void rec(int i, const string& digits, string& curr, vector<string>&res){
        if(i==digits.size()){
            res.push_back(curr);
        }
        for(const char& c:mp[digits[i]]){
            curr.push_back(c);
            rec(i+1,digits,curr,res);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string>res;
        string curr;
        rec(0,digits,curr,res);
        return res;
    }
};
