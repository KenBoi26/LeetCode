class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;

        while(start <= end){
            int mid = (start+end)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end--;
            else start++;
        }

        return -1;
    }
};