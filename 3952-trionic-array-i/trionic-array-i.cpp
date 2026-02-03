class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int count = 1;
        if(nums.size() <= 3) return false;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] < nums[i] && (count == 1 || count == 3)){
                continue;
            }
            if(nums[i-1] > nums[i] && count == 1 && i>=2){
                count++;
                continue;
            }
            if(nums[i-1] > nums[i] && count == 2){
                continue;
            }
            if(nums[i-1] < nums[i] && count == 2){
                count++;
                continue;
            }
            return false;
        }

        return true && (count == 3);
    }
};