class Solution {
public:
    stack<string> st;
    vector<string> result;

    void backtrack(int open_count, int closed_count, int n){
        if(open_count == closed_count && open_count == n){
            string temp="";
            stack<string> temp_stack = st;

            while(!temp_stack.empty()){
                temp = temp_stack.top() + temp;
                temp_stack.pop();
            }

            result.push_back(temp);
        }

        if(open_count < n){
            st.push("(");
            backtrack(open_count+1, closed_count, n);
            st.pop();
        }

        if(closed_count < open_count){
            st.push(")");
            backtrack(open_count, closed_count+1, n);
            st.pop();
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack(0,0,n);
        return result;
    }
};