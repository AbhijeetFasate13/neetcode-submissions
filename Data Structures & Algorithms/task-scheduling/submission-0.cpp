class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        int maxFreq = 0;
        for (char task : tasks) {
            freq[task]++;
            maxFreq = max(maxFreq, freq[task]);
        }
        int countMax = 0;
        for (auto& p : freq) {
            if (p.second == maxFreq) countMax++;
        }
        return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + countMax);
    }
};