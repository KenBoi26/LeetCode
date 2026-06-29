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
        if(delete_stack.size() == 0){
            while(insert_stack.size() > 0){
                int temp = insert_stack.top();
                insert_stack.pop();
                delete_stack.push(temp);
            }
        }
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
        return delete_stack.top();
    }
    
    bool empty() {
        if(delete_stack.size() == 0){
            while(insert_stack.size() > 0){
                int temp = insert_stack.top();
                insert_stack.pop();
                delete_stack.push(temp);
            }
        }
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