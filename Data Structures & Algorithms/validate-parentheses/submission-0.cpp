class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!st.empty()){
                char c = st.top();
                if((c=='{' and s[i]=='}') or (c=='(' and s[i]==')') or (c=='[' and s[i]==']')){
                    st.pop();
                    continue;
                }
            }
            st.push(s[i]);
        }
        return st.empty();
    }
};
