class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int it=1;
        while(true){
            int start = it;
            bool flag = true;
            for(auto i:nums){
                start += i;
                if(start < 1){
                    flag = false;
                    break;
                }
            }

            if(flag) return it;

            it++;
        }

        return -1;
    }
};