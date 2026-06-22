class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left_sum = 0;
        int right_sum = 0;

        for(auto i:nums){
            right_sum += i;
        }

        for(int i=0; i<nums.size(); i++){
            if(left_sum == right_sum-nums[i]) return i;

            left_sum += nums[i];
            right_sum -= nums[i];

        }

        return -1;
    }
};