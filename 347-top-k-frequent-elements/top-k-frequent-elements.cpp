class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto i :nums){
            mp[i]++;
        }
        vector<int> ans;

        while(k>0){
            int mx = -1;
            int  key = -1;
            for(auto i:mp){
                if(i.second>mx){
                    mx = i.second;
                    key = i.first;
                }
            }
            ans.push_back(key);
            mp.erase(key);
            k--;

        }

        return ans;
    }
};