class FindSumPairs {
public:

    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int i : this->nums2){
            freq2[i]++;
        }
    }
    
    void add(int index, int val) {
        freq2[nums2[index]]--;
        nums2[index] += val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int counter = 0;
        for(int i : nums1){
            if(freq2.count(tot-i)){
                counter += freq2[tot-i];
            }
        }

        return counter;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */