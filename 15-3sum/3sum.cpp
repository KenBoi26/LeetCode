class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& numbers) {
        vector<vector<int>> result;
        int n = numbers.size();
        sort(numbers.begin(), numbers.end());

        for(int i=0; i<n-2; i++){
            if(i>0 && numbers[i] == numbers[i-1]) continue;

            int l=i+1;
            int r=n-1;

            while(l<r){
                if(numbers[i]+numbers[l]+numbers[r] == 0){
                    result.push_back({numbers[i], numbers[l], numbers[r]});
                    while(l<r && numbers[l] == numbers[l+1]){
                        l++;
                    }
                    while(l<r && numbers[r] == numbers[r-1]){
                        r--;
                    }
                    l++;
                    r--;
                }else if(numbers[i]+numbers[l]+numbers[r] < 0){
                    l++;
                }else{
                    r--;
                }
                
            }
        }
        return result;
    }
};