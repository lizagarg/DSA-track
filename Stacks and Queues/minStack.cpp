class MinStack {
public:
    stack<long long> st;
    long long mini = INT_MAX;

    MinStack() {

    }
    
    void push(int value) {
        long long val = value;
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
                st.push(2 * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if (!st.empty()) {
            long long topp = st.top();
            st.pop();
            if (topp < mini)  // it is a modified value so update mini
                mini = (2 * mini) - topp;
        }
    }
    
    int top() {
        if (!st.empty()) {
            long long topp = st.top();
            if (topp < mini) { // it is a modified value 
                return mini;
            } else {
                return topp;
            }
        }
        return -1; // Return -1 if stack is empty 
    }
    int getMin() {
        return mini;
    }
};