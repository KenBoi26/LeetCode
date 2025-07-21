class Solution {
public:

    int maxElement(unordered_map<char, int> mp){
        int mx = 0;
        for(auto i:mp){
            mx = max(i.second, mx);
        }

        return mx;
    }

    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int result=0;

        unordered_map<char,int> mp;

        for(int r=0; r<s.length(); r++){
            char new_char = s[r];
            mp[new_char] +=1;
            while((r-l+1) - maxElement(mp) > k){
                mp[s[l]] -= 1;
                l+=1;
            }
            result = max(result, r-l+1);
        }

        return result;


    }
};
