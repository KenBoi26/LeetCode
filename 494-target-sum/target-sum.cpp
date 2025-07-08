class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for (int i : nums) {
            total += i;
        }

        if (abs(target) > total) return 0;

        vector<vector<int>> dp(n, vector<int>(2 * total + 1, INT_MIN));
        return solve(nums, 0, target, total, 0, dp);
    }

    int solve(vector<int>& nums, int index, int target, int total, int sum, vector<vector<int>>& dp) {
        if (index >= nums.size()) {
            return sum == target ? 1 : 0;
        }

        if (dp[index][total + sum] != INT_MIN) {
            return dp[index][total + sum];
        }

        int add = solve(nums, index + 1, target, total, sum + nums[index], dp);
        int subtract = solve(nums, index + 1, target, total, sum - nums[index], dp);

        return dp[index][total + sum] = add + subtract;
    }
};
