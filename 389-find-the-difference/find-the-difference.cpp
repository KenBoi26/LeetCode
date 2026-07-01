class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq_s(256,0);
        vector<int> freq_t(256,0);
        for(auto i:s){
            freq_s[i]++;
        }

        for(auto i:t){
            freq_t[i]++;
        }

        for(int i=0; i<256; i++){
            if(freq_s[i] != freq_t[i]) return (char)(i);
        }

        return ' ';
    }
};