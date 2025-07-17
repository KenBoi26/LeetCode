class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result=[]
        nums.sort()

        for i in range(len(nums)-1):
            if i>0 and nums[i] == nums[i-1]:
                continue
            
            l=i+1
            r=len(nums)-1

            while(l<r):
                current_sum = nums[i] + nums[l] + nums[r]

                if current_sum == 0:
                    result.append([nums[i],nums[l],nums[r]])

                    while l<r and nums[l] == nums[l+1]:
                        l+=1
                    
                    while l<r and nums[r] == nums[r-1]:
                        r-=1
                    
                    l+=1
                    r-=1
                elif current_sum < 0:
                    l+=1
                else:
                    r-=1
        
        return result