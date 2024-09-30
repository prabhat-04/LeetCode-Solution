class CustomStack {
    vector<int> stack;
    int maxSi;
public:
    CustomStack(int maxSize) {
        maxSi = maxSize;
    }
    
    void push(int x) {
        if(stack.size()>=maxSi) return;
        stack.push_back(x);
        return;
    }
    
    int pop() {
        if(stack.empty()) return -1;
        int ans = stack.back();
        stack.pop_back();
        return ans;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<stack.size() && i<k;i++){
            stack[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */