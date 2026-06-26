class Solution {
public:

    int calc(vector<int> &nums, int mid){
        int count = 0;

        for(auto i:nums){
            count += ceil((double)(i)/(double)(mid));
        }

        return count;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        int ans = -1;
        while(left <= right){
            
            int mid = left+(right-left)/2;

            if(calc(nums, mid) > threshold){
                left = mid+1;
            }else{
                ans = mid;
                right = mid-1;
            }

        }

        return ans;
    }
};