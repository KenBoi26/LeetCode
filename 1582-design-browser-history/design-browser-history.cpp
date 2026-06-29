class BrowserHistory {
public:

    stack<string> history;
    stack<string> next;

    BrowserHistory(string homepage) {
        history.push(homepage);
    }
    
    void visit(string url) {
        history.push(url);
        while(next.size() > 0) next.pop();
    }
    
    string back(int steps) {
        int x = history.size()-1;
        while(steps-- > 0 && x-- > 0) {
            next.push(history.top());   
            history.pop();
        }

        return history.top();
    }
    
    string forward(int steps) {
        int x = next.size()-1;
        if(x < 0) return history.top();
        while(steps-- && x-- >= 0){
            history.push(next.top());
            next.pop();
        }

        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */