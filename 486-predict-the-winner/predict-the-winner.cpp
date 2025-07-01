class Solution {
public:

    bool Awin(vector<int>&nums, int left, int right, bool aturn, int suma, int sumb){
        if(left > right){
            return suma >= sumb;
        }
        if(aturn){
            return (Awin(nums, left+1, right, false, suma+nums[left], sumb) || Awin(nums, left, right-1, false, suma+nums[right], sumb));
        }else{
            return (Awin(nums, left+1, right, true, suma, sumb+nums[left]) && Awin(nums, left, right-1, true, suma, sumb+nums[right]));
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        return Awin(nums, 0, nums.size()-1, true, 0, 0);
    }
};