class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<long long> dp(1<<n, INT_MAX);

        dp[0] = 0;

        for(int mask = 0; mask < (1<<n); mask++){
            int already = __builtin_popcount(mask);
            for(int i=0; i<n; i++){
                if((mask & (1<<i)) == 0){
                    dp[mask|(1<<i)] = min(dp[mask|(1<<i)], dp[mask] + (nums1[already]^nums2[i]));
                }
            }
        }

        return (int)dp.back();

    }
    
};