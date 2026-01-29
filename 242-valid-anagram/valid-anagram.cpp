class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq1(256,0);
        vector<int> freq2(256,0);

        if(s.length() != t.length()) return false;

        for(int i=0; i<s.length(); i++){
            freq1[s[i]]++;
            freq2[t[i]]++;
        }

        return freq1==freq2;
    }
};