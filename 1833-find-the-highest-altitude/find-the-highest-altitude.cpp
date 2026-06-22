class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current_sum = 0;
        int highest = 0;

        for(auto i:gain){
            current_sum += i;
            if(current_sum > highest) highest = current_sum;
        }

        return highest;

    }
};