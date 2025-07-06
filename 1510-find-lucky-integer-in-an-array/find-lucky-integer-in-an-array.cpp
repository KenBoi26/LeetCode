class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp;
        for(auto i:arr){
            mp[i]++;
        }

        int mx=-1;
        for(auto i:mp){
            if(i.second == i.first){
                mx = i.first;
            }
        }

        return mx;
    }
};