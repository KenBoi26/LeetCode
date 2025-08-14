class Solution {
public:
    string largestGoodInteger(string num) {
        string large = "";
        for (int i = 0; i <= num.size() - 3; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string temp(3, num[i]);
                if (temp > large) {
                    large = temp;
                }
            }
        }
        return large;
    }
};