class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
       s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()) {
            int popped= s2.top();
            s2.pop();
            return popped;
        }
        else{
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            int popped= s2.top();
            s2.pop();
            return popped;

        }

    }
    
    int peek() {
        if(!s2.empty()) return s2.top();
        else {
             while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    bool empty() {
         return s1.empty() && s2.empty();
    }
};

