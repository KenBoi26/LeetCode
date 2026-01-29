class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            while(!isalnum(s[l]) && l<r){
                if(!isalnum(s[l])){
                    l++;
                }
            }
            while(!isalnum(s[r]) && l<r){
                if(!isalnum(s[r])){
                    r--;
                }
            }

            if(tolower(s[l]) != tolower(s[r])) return false;


            l++;
            r--;

        }

        return true;
    }
};