class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        while(left < right){
            int mid = left+(right-left)/2;

            // cout << left << " " << right << endl;

            if(nums[left] <= nums[mid]){
                if(nums[mid] > nums[right]){
                    left = mid + 1;
                }else{
                    right = mid;
                }

            }else{
                if(nums[mid] < nums[right]){
                    right = mid;
                }else{
                    left = mid+1;
                }
            }
        }

        return min(nums[left], nums[right]);
    }
};