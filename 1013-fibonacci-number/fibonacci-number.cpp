class Solution {
public:
    vector<long long> dp;

    Solution(){
        dp = vector<long long>(31, -1);
    }

    int fib(int n) {
        
        if(n<=1){
            return n;
        }

        if(dp[n] != -1) return dp[n];
        long long ans = fib(n-1) + fib(n-2);

        dp[n] = ans;
        return dp[n];
    }
};