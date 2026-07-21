class Solution {
    bool isOperator(string& s){
        return s=="+" or s=="-" or s=="*" or s=="/";
    }
    int doMath(const int& a, const int& b, const string& op){
        if(op=="+"){
            return a+b;
        }else if(op=="-"){
            return a-b;
        }else if(op=="*"){
            return a*b;
        }else{
            return a/b;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(isOperator(tokens[i])){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(doMath(second,first,tokens[i]));
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
