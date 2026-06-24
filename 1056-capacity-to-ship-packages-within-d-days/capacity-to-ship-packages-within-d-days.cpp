class Solution {
public:

    int calc(vector<int>weights, int mid){
        int count = 1;
        int total = 0;

        for(auto i:weights){
            if(total + i <= mid){
                total += i;
            }else{
                total = i;
                count++;
            }
        }

        return count;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;

        for(auto i:weights) right += i;

        int ans = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(calc(weights, mid) <= days){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return ans;
    }
};