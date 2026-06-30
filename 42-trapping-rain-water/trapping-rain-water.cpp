class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int total = 0;
        int current = 0;

        while(current < height.size()){
            while(!st.empty() && height[current] > height[st.top()]){
                int top_index = st.top();
                st.pop();

                if(st.empty()){
                    break;
                }

                int distance = current - st.top() - 1;

                int bounded_height = min(height[current], height[st.top()]) - height[top_index];

                total += distance * bounded_height;
            }

            st.push(current);
            current++;
        }



        return total;

    }
};