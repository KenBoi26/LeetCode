class Solution {
public:
    bool isPalindrome(string s) {
        int l=0, r=s.length()-1;
        while(l<r){
            if(s[l] == ' ' || !isalnum(s[l])){
                l++;
                continue;
            }
            if(s[r] == ' ' || !isalnum(s[r])){
                r--;
                continue;
            }

            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};