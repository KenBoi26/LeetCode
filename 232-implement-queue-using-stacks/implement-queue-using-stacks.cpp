class MyQueue {
public:

    stack<int> insert_stack;
    stack<int> delete_stack;
    
    MyQueue() {
    
    }
    
    void push(int x) {
        insert_stack.push(x);
    }
    
    int pop() {
        int temp = peek();
        int print = delete_stack.top();
        delete_stack.pop();
        return print;
        
    }
    
    int peek() {
        if(delete_stack.size() == 0){
            while(insert_stack.size() > 0){
                int temp = insert_stack.top();
                insert_stack.pop();
                delete_stack.push(temp);
            }
        }
        if(delete_stack.size() == 0 && insert_stack.size() == 0) return -1;
        return delete_stack.top();
    }
    
    bool empty() {
        int temp = peek();
        return delete_stack.size() == 0;
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