class Solution {
public:

    string reverseWords(string s) {
       stack<string> bank;
       string temp = "";
       for(char i:s){
            if(i == ' '){
                if (!temp.empty()) {
                    bank.push(temp);
                    temp = "";
                }
            }else{
                temp += i;
            }
       }
       if(!temp.empty()) bank.push(temp);
       
       string finale = "";
       while(bank.size() > 1){
            finale += bank.top() + " ";
            bank.pop();
       }
       finale += bank.top();
       bank.pop();

       return finale;

    }
};