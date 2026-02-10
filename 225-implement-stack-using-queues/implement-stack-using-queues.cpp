class MyStack {
public:
    queue<int> stack;
    queue<int> temp;
    MyStack() {
        
    }
    
    void push(int x) {
        temp.push(x);
        while(!stack.empty()){
            temp.push(stack.front());
            stack.pop();
        }
        swap(stack, temp);
    }
    
    int pop() {
        int temp = stack.front();
        stack.pop();
        return temp;
    }
    
    int top() {
        return stack.front();
    }
    
    bool empty() {
        return stack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */