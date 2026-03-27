class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        min_length = 1000
        for i in strs:
            min_length = min(min_length, len(i))
        
        prefix = ""
        for i in range(min_length):
            for j in strs:
                if i == len(j) or j[i] != strs[0][i]:
                    return prefix
            
            prefix += strs[0][i]
        
        return prefix