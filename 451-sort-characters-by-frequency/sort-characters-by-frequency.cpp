class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char i:s){
            mp[i]++;
        }

        vector<pair<int,char>> v_mp;
        for(auto const& [ch,freq]: mp){
            v_mp.push_back({freq, ch});
        }

        sort(v_mp.begin(), v_mp.end(), [] (const pair<int,char> &a, const pair<int,char> &b) {
            return a.first > b.first;
        });

        string word = "";
        for(auto i:v_mp){
            for(int j=1;j<=i.first;j++){
                word+=i.second;
            }
        }

        return word;
    }
};