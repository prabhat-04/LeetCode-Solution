class MinStack {
    stack<long long int> st;
    long long int mini = INT_MAX;
public:
    MinStack() {
    }
    
    void push(long long int val) {
            if(val<mini){
                st.push(2LL *val-mini);
                mini = val;
            }
            else
                st.push(val);
        
    }
    
    void pop() {
        if(st.top()<mini){
            mini = 2 * mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<mini)
            return static_cast<int> (mini);
        return static_cast<int>(st.top());
    }
    
    int getMin() {
        return static_cast<int>(mini);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */