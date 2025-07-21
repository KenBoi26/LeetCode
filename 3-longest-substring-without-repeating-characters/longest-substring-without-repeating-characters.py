class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0
        st = []
        ml = 0
        l = 0
        r = 0

        while(r<len(s)):
            if s[r] in st:
                idx = st.index(s[r])
                st = st[idx+1:]
                l = idx + 1
            st.append(s[r])
            ml = max(ml, len(st))
            r+=1
        

        return ml