class Solution {
public:
    int countZero(vector<int> &nums, int l, int r){
        int count=0;
        while(l<=r){
            if(nums[l] == 0) count++;
            l++;
        }

        return count;
    }
    int minSwaps(vector<int>& nums) {
        int count = 0;
        for(auto i:nums){
            if(i==1) count++;
        }
        if(count == 0) return 0;
        vector<int> dup = nums;
        for(auto i:nums){
            dup.push_back(i);
        }

        int l = 0;
        int r = 0;
        int zeros=0;
        while(r<count){
            if(dup[r++] == 0) zeros++;
        }
        int min_swaps = zeros;

        while(r<=nums.size()-1+count){
            if(dup[l++] == 0) zeros--;
            if(dup[r++] == 0) zeros++;
            min_swaps = min(zeros,min_swaps);
        }

        return min_swaps;
    }
};