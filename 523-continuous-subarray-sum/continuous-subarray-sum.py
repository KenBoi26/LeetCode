class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        d = {0:-1}
        summ = 0
        for i in range(len(nums)):
            summ += nums[i]
            if summ%k not in d:
                d[summ%k] = i
            elif i - d[summ%k] > 1:
                return True
        
        return False