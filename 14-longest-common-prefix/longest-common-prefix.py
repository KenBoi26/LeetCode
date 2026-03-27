class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        min_length = 1000
        for i in strs:
            min_length = min(min_length, len(i))
        
        prefix = ""
        for i in range(min_length):
            temp = strs[0][:i+1]
            for j in strs:
                if j[:i+1] != temp:
                    return prefix
            
            prefix += strs[0][i]
        
        return prefix