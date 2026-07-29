class Solution {
    bool isPal(string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    void rec(int i, const string &s,
             vector<string> &curr,
             vector<vector<string>> &ans) {
        if (i == s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            string currSub = s.substr(i, j - i + 1);
            if (isPal(currSub)) {
                curr.push_back(currSub);
                rec(j + 1, s, curr, ans);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        rec(0, s, curr, ans);
        return ans;
    }
};