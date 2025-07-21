class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int ml = 0;

        for(int right=0, left = 0; right<s.length(); right++){
            char current = s[right];

            if(mp.count(current)){
                left = max(left, mp[current]+1);
            }

            mp[current] =  right;
            ml = max(ml, right - left +1);
        }

        return ml;
    }
};