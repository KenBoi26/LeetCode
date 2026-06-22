class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        
        for(auto &i:bookings){
            for(int j=i[0]-1; j<i[1]; j++){
                ans[j] += i[2];
            }
        }

        return ans;
    }
};