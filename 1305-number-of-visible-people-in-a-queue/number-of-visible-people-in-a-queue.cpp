class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        vector<int> ans(heights.size(), 0);

        for(int i=heights.size()-1; i>=0; i--){
            while(!st.empty() && st.top() < heights[i]){
                ans[i]++;
                st.pop();
            }

            if(!st.empty()) ans[i]++;

            st.push(heights[i]);
        }

        return ans;
    }


};