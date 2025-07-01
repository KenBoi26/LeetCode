class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> mx, mn;
        int l = 0, ans = 0;

        for(int r = 0; r<=nums.size()-1; r++){
            while(!mn.empty() && mn.back() > nums[r]){
                mn.pop_back();
            }
            while(!mx.empty() && mx.back() < nums[r]){
                mx.pop_back();
            }

            mn.push_back(nums[r]);
            mx.push_back(nums[r]);

            while(mx.front() - mn.front() > limit){
                if(mx.front() == nums[l]){
                    mx.pop_front();
                }
                if(mn.front() == nums[l]){
                    mn.pop_front();
                }
                
                l++;
            }

            ans = max(ans, r-l+1);
        }


        return ans;
        
    }
};