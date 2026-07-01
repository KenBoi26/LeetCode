class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(auto i:nums){
            if(!freq[i]) freq[i] = 0;

            freq[i]++;
        }

        int max_length = 0;
        int max_freq = 0;
        for(auto i:freq){
            if(max_freq < i.second){
                max_freq = i.second;
                max_length = 1;
            }else if(i.second == max_freq){
                max_length++;
            }

        }

        return max_length*max_freq;
    }
};