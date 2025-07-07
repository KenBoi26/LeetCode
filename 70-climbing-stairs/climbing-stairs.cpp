class Solution {
public:

    int helper(int n, int i, vector<int> &dp){
        if(i>n) return 0;
        if(i==n) return 1;
        
        if(dp[i] != -1) return dp[i];
        dp[i] = helper(n,i+1,dp) + helper(n,i+2,dp);
        return dp[i];
    }

    int climbStairs(int n) {
        

        vector<int> dp(n+1, -1);

        return helper(n,0,dp);
    }
};