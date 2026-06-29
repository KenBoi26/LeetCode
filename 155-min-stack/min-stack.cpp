class MinStack {
public:

    stack<int> st;
    stack<int> min_stack;

    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);

        if(min_stack.size() == 0){
            min_stack.push(value);
            return;
        }

        if(min_stack.top() > value) min_stack.push(value);
        else min_stack.push(min_stack.top());
    }
    
    void pop() {
        if(st.size() == 0) return;

        st.pop();
        min_stack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */