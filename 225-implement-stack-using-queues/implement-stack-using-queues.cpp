class MyStack {
public:
    queue<int> q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n = q.size()-1;
        while(n-- > 0){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        int print = q.front();
        q.pop();
        return print;
    }
    
    int top() {
        int n = q.size()-1;
        while(n-- > 0){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        int print = q.front();
        int temp = q.front();
        q.pop();
        q.push(temp);
        return print;
    }
    
    bool empty() {
        return q.size() == 0;
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