class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for i in nums:
            index = abs(i) -1
            if nums[index] < 0:
                return abs(i) 
            nums[index] *= -1
        
        return -1