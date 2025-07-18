class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();

        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                return mid;
            }else if(target < nums[mid]){
                r = mid;
            }else{
                l = mid+1;
            }
        }

        return -1;
    
    }
};