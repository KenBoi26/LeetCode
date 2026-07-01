class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> freq_s(256,0);
        vector<int> freq_t(256,0);

        if(s.size() != t.size()) return false;

        for(int i=0; i<s.size(); i++){
            if(freq_s[s[i]] != freq_t[t[i]]) return false;
            freq_s[s[i]] = i+1;
            freq_t[t[i]] = i+1;
        }

        return true;
    }
};