class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.size();
        int i = length-1;
        int count = 0;
        while(s[i] == ' ' && count == 0){
            i--;
        }
        while(s[i] != ' ' && i >= 0){
            count++;
            i--;
            if(i<0) return count;
        }

        return count;
    }
};