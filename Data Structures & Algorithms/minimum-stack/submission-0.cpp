class MinStack {
    vector<int>stack;
    int minPos;
    int min;
public:
    MinStack() {
        minPos = -1;
        min = INT_MAX;
    }
    
    void push(int val) {
        if(min>val){
            min = val;
            minPos = stack.size();
        }
        stack.push_back(val);
    }
    
    void pop() {
        if(stack.size()>0)
            stack.pop_back();
        if(minPos==stack.size()){
            minPos = -1;
            min = INT_MAX;
            for(int i=stack.size()-1;i>=0;i--){
                if(min>stack[i]){
                    min = stack[i];
                    minPos = i;
                }
            }
        }
        return;
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min;
    }
};
