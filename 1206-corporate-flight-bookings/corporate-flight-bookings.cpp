class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n+2,0);
        
        for(auto &i:bookings){
            ans[i[0]] += i[2];
            ans[i[1]+1] -= i[2];
        }

        for(auto i:ans) cout << i << " ";

        vector<int> prefix(n);
        prefix[0] = ans[1];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + ans[i+1];
        }
        

        return prefix;
    }
};