class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        length = len(s)
        i = length - 1
        count = 0
        
        while(s[i] == ' ' and count == 0):
            i -= 1

        while(i >= 0 and s[i] != ' '):
            count += 1
            i -= 1

            if(i < 0):
                return count
        
        return count