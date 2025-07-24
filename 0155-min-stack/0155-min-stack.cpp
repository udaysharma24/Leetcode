class MinStack {
public:
    stack<int> s;
    MinStack() {
        stack<int> s;
    }
    
    void push(int val) {
        s.push(val);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return (s.top());
    }
    
    int getMin() {
        stack<int> sc(s);
        int mini= sc.top();
        while(sc.empty()==false)
        {
            if((sc.top())<mini)
                mini=sc.top();
            sc.pop();
        }
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