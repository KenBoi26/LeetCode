class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        ps = []
        ps.append(nums[0])

        for i in range(1, len(nums)):
            ps.append(ps[-1] + nums[i])
        
        return ps
