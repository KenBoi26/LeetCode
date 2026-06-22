class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> prefix_sum(nums.size());

        prefix_sum[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }

        return prefix_sum;
    }
};