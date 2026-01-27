class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = (start+end)/2;
            if(nums[mid] == target){
                int l = mid;
                int r = mid;

                while(nums[l] == target){
                    l--;
                    if(l<0) break;
                }
                
                while(nums[r] == target){
                    r++;
                    if(r>nums.size()-1) break;
                }
                return {l+1,r-1};
            }else if(nums[mid] < target){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }

        return {-1,-1};
    }
};