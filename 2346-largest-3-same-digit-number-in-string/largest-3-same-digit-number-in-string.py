class Solution:
    def largestGoodInteger(self, num: str) -> str:
        large = ""
        for i in range(len(num)-2):
            if num[i] == num[i+1] == num[i+2]:
                if num[i]*3 > large:
                    large = num[i]*3
                        
        return large
