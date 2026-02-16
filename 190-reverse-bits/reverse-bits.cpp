class Solution {
public:
    int reverseBits(int n) {
        stack<int> st;
        for (int i = 0; i < 32; i++) {
            st.push(n & 1);
            n >>= 1;
        }

        int i=0;
        int ans = 0;
        while(!st.empty()){
            ans += pow(2,i)*st.top();
            st.pop();
            i++;
        }

        return ans;
    }
};