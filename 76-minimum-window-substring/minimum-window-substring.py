class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l = 0
        r = 0

        if s == t or t == "":
            return t

        result = (-1,-1)
        minimum_length = len(s)

        d1 = dict() # frequency of T
        d2 = dict() # frequency of current window

        for i in t:
            d1[i] = 1 + d1.get(i,0)

        have = 0
        need = len(d1)
        
        while r < len(s):
            d2[s[r]] = 1 + d2.get(s[r],0)

            if s[r] in d1 and d2[s[r]] == d1[s[r]]:
                have += 1
            
            while have == need:
                if minimum_length >= r-l+1:
                    minimum_length = r-l+1
                    result = (l,r)
                

                d2[s[l]] -= 1
                if s[l] in d1 and d2[s[l]] < d1[s[l]]:
                    have -= 1
                
                l += 1
            
            r += 1
        
        return s[result[0]:result[1]+1]