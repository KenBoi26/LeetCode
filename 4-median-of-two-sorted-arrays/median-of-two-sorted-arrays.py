class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        median = (len(nums1) + len(nums2))//2

        next_num = 0
        prev = 0

        i = 0
        j = 0

        while i+j <= median:
            prev = next_num

            if i < len(nums1) and (j >= len(nums2) or nums1[i] <= nums2[j]):
                next_num = nums1[i]
                i += 1
            else:
                next_num = nums2[j]
                j += 1
            
        if (len(nums1)+len(nums2))%2 == 0:
            return (prev+next_num)/2
        else:
            return next_num