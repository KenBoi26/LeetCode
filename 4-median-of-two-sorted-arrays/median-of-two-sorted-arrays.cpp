class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        bool flag = false;
        if((n+m)%2 == 0){
            flag = true;
        }
        int median = (n+m)/2;

        int i=0, j=0;
        int curr=0, prev=0;

        while(i+j <= median){
            prev = curr;
            if(i < n && (j >= m || nums1[i] <= nums2[j])){
                curr = nums1[i];
                i++;
            }else{
                curr = nums2[j];
                j++;
            }
        }

        if(!flag){
            return curr;
        }else{
            return (prev+curr)/2.0;
        }
        
        
        
    }
};