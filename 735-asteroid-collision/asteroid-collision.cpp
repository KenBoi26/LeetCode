class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto i:asteroids){
            if(i>0){
                st.push(i);
            }
            
            if(i<0){
                bool destroyed = false;
                while(!st.empty() && st.top() > 0){
                    if(st.top() < -i){
                        st.pop();
                    }
                    else if(st.top() == -i){
                        st.pop();
                        destroyed = true;
                        break;
                    }else{
                        destroyed = true;
                        break;
                    }
                }
                if(!destroyed){
                    st.push(i);
                }
            }
        }
        if(st.empty()) return {};
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};