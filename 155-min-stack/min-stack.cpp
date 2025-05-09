class MinStack {
public:
    stack<long long> s;
    long long  mini;
    MinStack() {
                // while (!s.empty()) s.pop();

    }
    
    void push(int val) {
        if(s.empty()){
            mini = val;
            s.push(val);
        }
        else{
            if(val>mini) s.push(val);
            else{
                s.push(2LL *val-mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(s.empty()){
            return ;
        }
        long long  x = s.top();
        s.pop();
        if(x<mini){
            mini = 2*mini-x;
        }
    }
    
    int top() {
        if(s.empty()) return 0;
        long long x=s.top();
        if(mini <x) return x;
        return mini ;

    }
    
    int getMin() {
        return mini;
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