class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();

        if(n == 0 || s[0] == '0') return 0;
        
        vector<int> dp(n+1,0);

        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            int firstDigit = s[i-1] - '0';
            int secondDigit = stoi(s.substr(i-2, 2));

            if(firstDigit > 0){
                dp[i] += dp[i-1];
            }

            if(secondDigit >= 10 && secondDigit <= 26){
                dp[i] += dp[i-2];
            }

        }

        return dp[n];
        
    }

    
};