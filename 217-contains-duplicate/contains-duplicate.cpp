class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp1;
        for(auto i:nums){
            mp1[i]++;
            if(mp1[i] > 1){
                return true;
            }
        }

        return false;
    }
};