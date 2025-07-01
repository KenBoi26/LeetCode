class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool flag = true;

        for(char i : s){
            if(i == '(' || i == '{' || i == '['){
                st.push(i);
            }else if(i == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }else{
                    flag = false;
                }
            }else if(i == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    flag = false;
                }
            }else if(i == '}'){
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }else{
                    flag = false;
                }
            }


        }

        return flag && st.empty();
    }
};