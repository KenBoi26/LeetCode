class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.length() < k){
            string temp="";
            for(char i : word){
                temp += ++i;
            }
            word += temp;
        }
        
        int index = (word.length() >= k) ? k-1 : word.length() - k - 1;
        return word[index];
        }
};














