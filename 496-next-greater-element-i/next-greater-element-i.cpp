class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        vector<int> nge(n);
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i] = -1;
            }else{
                nge[i] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> result;

        for(auto i:nums1){
            int j =0;
            while(j<nums2.size()){
                if(nums2[j] == i){
                    break;
                }
                j++;
            }
            result.push_back(nge[j]);
        }

        return result;
    }
};