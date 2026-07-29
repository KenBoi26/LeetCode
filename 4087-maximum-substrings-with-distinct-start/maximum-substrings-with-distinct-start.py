class Solution:
    def maxDistinct(self, s: str) -> int:
        se = set()
        for i in s:
            se.add(i)
        
        return len(se)
        