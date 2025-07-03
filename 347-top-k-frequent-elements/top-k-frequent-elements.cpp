class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        vector<pair<int, int>> freqVector;
        for (auto const& [num, freq] : freqMap) {
            freqVector.push_back({freq, num});
        }

        sort(freqVector.begin(), freqVector.end(), [](const pair<int,int> &a, const pair<int,int> &b){ 
            return a.first>b.first;
        });

        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(freqVector[i].second);
        }

        return ans;
    }
};