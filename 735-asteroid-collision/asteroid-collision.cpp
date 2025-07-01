class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(auto i:asteroids){
            if(st.empty() || i > 0 || st.top()<0){
                st.push(i);
            }else{
                bool flag = false;
                while(!st.empty() && st.top() > 0 && i<0){
                    if(st.top() < abs(i)){
                        st.pop();
                    }else if(st.top() == abs(i)){
                        st.pop();
                        flag = true;
                        break;
                    }else{
                        flag = true;
                        break;
                    }
                }

                if(!flag){
                    st.push(i);
                }
            }
        }

        vector<int> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        return v;


    }
};