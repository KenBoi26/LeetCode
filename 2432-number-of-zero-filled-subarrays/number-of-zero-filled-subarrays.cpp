class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total = 0;
        long long zeros = 0;

        for(auto i:nums){
            if(i == 0){
                zeros++;
            }else{
                zeros=0;
            }

            total += zeros;
        }

        return total;
    }
};