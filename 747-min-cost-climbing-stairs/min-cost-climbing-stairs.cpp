class Solution {
public:
    vector<long long> dp;
    Solution(){
        dp = vector<long long> (1001,-1);
    }

    int helper(vector<int> &cost, int i){
        if(i>=cost.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int step1 = cost[i] + helper(cost,i+1);
        int step2 = cost[i] + helper(cost, i+2);

        dp[i] = min(step1,step2);
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        

        return min(helper(cost,0), helper(cost,1));
    }
};