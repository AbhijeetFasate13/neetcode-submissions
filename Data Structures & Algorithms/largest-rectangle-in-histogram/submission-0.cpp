class Solution {
    vector<int> getPreviousLesserElements(vector<int>& heights){
        int n = heights.size();
        stack<int>st;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            res[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> getNextLesserElements(vector<int>& heights){
        int n = heights.size();
        stack<int>st;
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            res[i] = st.empty()?n:st.top();
            st.push(i);
        }
        return res;
    }
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> previousLess = getPreviousLesserElements(heights);
        vector<int> nextLess = getNextLesserElements(heights);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,(nextLess[i]-previousLess[i]-1)*heights[i]);
        }
        return ans;
    }
};
