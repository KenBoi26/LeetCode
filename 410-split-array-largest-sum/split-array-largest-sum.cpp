class Solution {
public:

    int calc(vector<int>nums, int mid){
        int count = 1;
        int total = 0;

        for(auto i:nums){
            if(total + i <= mid){
                total += i;
            }else{
                total = i;
                count++;
            }
        }

        return count;
    }

    int splitArray(vector<int>& nums, int k) {

        int left = *max_element(nums.begin(), nums.end());
        int right = 0;

        for(auto i:nums) right += i;

        int ans = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(calc(nums, mid) <= k){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return ans;
    
    }
};