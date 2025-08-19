class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        total = 0
        zeros = 0

        for i in nums:
            if i == 0:
                zeros+=1
            else:
                zeros = 0
            
            total += zeros
        
        return total
