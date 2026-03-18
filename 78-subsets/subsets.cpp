class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};

        for(auto i:nums){
            int size = res.size();

            for(int j=0; j<size; j++){
                vector<int> sub = res[j];
                sub.push_back(i);
                res.push_back(sub);
            }
        }

        return res;
    }
};