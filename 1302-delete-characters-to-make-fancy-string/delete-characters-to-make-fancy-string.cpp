
class Solution {
public:
    string makeFancyString(string s) {
        int counter = 1;
        char prev = ' ';
        string ans = "";
        for(auto i : s){
            

            if(i == prev){
                counter++;
                if(counter<3){
                    ans+=i;
                }
            }else{
                counter = 1;
                ans += i;
                prev = i;
            }

            
        }

        return ans;
    }
};