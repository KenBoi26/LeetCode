class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result=0;
        int n = nums.size();
        int curr = 0;
        for(int i=0; i<n; i++){
            result = result ^ nums[i] ^ i;
        }
        result^=n;

        return result;
    }
};