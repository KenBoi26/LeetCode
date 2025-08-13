class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        d=[]
        for i in nums:
            temp = ''
            for j in str(i):
                temp += str(mapping[int(j)])
            
            d.append((i, int(temp)))
        
        result = []
        d.sort(key=lambda item:item[1])
        result = [item[0] for item in d]
        
        return result