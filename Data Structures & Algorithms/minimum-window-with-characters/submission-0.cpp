class Solution {
    bool compareFreq(vector<int>& need, vector<int>& have) {
        for (int i = 0; i < 52; i++) {
            if (have[i] < need[i])
                return false;
        }
        return true;
    }

    vector<int> getFreq(string &s) {
        vector<int> freq(52);

        for(char c : s) {
            if(c >= 'a' && c <= 'z')
                freq[c - 'a']++;
            else
                freq[c - 'A' + 26]++;
        }

        return freq;
    }

public:
    string minWindow(string s, string t) {
        vector<int> need = getFreq(t);
        vector<int> have(52);
        int l = 0;
        string ans;
        for(int r = 0; r < s.size(); r++) {
            if(s[r] >= 'a' && s[r] <= 'z')
                have[s[r] - 'a']++;
            else
                have[s[r] - 'A' + 26]++;
            while(compareFreq(need, have)) {
                if(ans.empty() || r - l + 1 < ans.size())
                    ans = s.substr(l, r - l + 1);
                if(s[l] >= 'a' && s[l] <= 'z')
                    have[s[l] - 'a']--;
                else
                    have[s[l] - 'A' + 26]--;
                l++;
            }
        }
        return ans;
    }
};