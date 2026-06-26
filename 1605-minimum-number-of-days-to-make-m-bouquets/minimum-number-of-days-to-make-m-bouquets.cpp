class Solution {
public:

    int calc(vector<int> bloomDay, int mid, int k){
        for(int i=0; i<bloomDay.size(); i++){
            bloomDay[i] -= mid; 
        }
        int count = 0;
        int prev = -1;
        int temp = 0;
        
        for(auto i:bloomDay){
            
            if(i <= 0){
                temp++;
            }else{
                temp = 0;
            }
            // cout << prev << " " << i << " " << k << endl;
            prev = i;

            if(temp >= k){
                count++;
                // cout << "hi" << count;
                temp = 0;
            }
        }

        // cout << count << " " << mid << endl;
        return count;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;
        while(left <= right){
            int mid = left+(right-left)/2;

            if(calc(bloomDay, mid, k) >= m){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return ans;
    }
};