class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            int index = (((i+nums[i])%n) + n)%n;
            result[i] = nums[index];
        }

        return result;
    }
};