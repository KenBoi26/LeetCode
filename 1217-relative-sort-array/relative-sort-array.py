class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        d = {}
        for i in arr1:
            if i not in d:
                d[i] = 0
            
            d[i] += 1
        result = []

        for i in arr2:
            for j in range(d[i]):
                result.append(i)
        
        remaining = []

        for i in arr1:
            if i not in result:
                remaining.append(i)
        
        remaining.sort()
        for i in remaining:
            result.append(i)

        return result