class Solution {
public:
    int maximum69Number (int num) {
        int maximum = num;
        string s = to_string(num);
        int length = s.size();

        for (int i = length - 1; i >= 0; --i) {
            int temp = num;
            if (s[length - i - 1] == '6') {
                temp = temp + pow(10, i) * 3;
            }
            if (temp > maximum) {
                maximum = temp;
            }
        }
        return maximum;
    }
};