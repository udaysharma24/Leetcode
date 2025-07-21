class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty())
            s2.push(x);
        else
            s1.push(x);
        return;
    }
    
    int pop() {
        if(s1.empty()==false)
        {
            while(s1.size()>1)
            {
                s2.push((s1.top()));
                s1.pop();
            }
            int temp= s1.top();
            s1.pop();
            while(s2.empty()==false)
            {
                s1.push((s2.top()));
                s2.pop();
            }
            return temp;
        }
        else
        {
            while(s2.size()>1)
            {
                s1.push((s2.top()));
                s2.pop();
            }
            int temp= s2.top();
            s2.pop();
            while(s1.empty()==false)
            {
                s2.push((s1.top()));
                s1.pop();
            }
            return temp;
        }
    }
    
    int peek() {
        if(s1.empty()==false)
        {
            while(s1.size()>1)
            {
                s2.push((s1.top()));
                s1.pop();
            }
            int temp= s1.top();
            while(s2.empty()==false)
            {
                s1.push((s2.top()));
                s2.pop();
            }
            return temp;
        }
        else
        {
            while(s2.size()>1)
            {
                s1.push((s2.top()));
                s2.pop();
            }
            int temp= s2.top();
            while(s1.empty()==false)
            {
                s2.push((s1.top()));
                s1.pop();
            }
            return temp;
        }
    }
    
    bool empty() {
        if(s1.size()==0 && s2.size()==0)
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */