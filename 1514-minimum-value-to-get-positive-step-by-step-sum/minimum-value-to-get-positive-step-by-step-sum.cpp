class Solution {
public:
    int minStartValue(vector<int>& nums) {
        vector<int> prefix_sum(nums.size()+1);

        int min = 1;

        for(int i=0;i<nums.size();i++){
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
            if(min > prefix_sum[i]) min = prefix_sum[i];
        }
        if(min > prefix_sum[nums.size()]) min = prefix_sum[nums.size()];


        if(min < 1) return min*-1 + 1;
        return min;
    }
};