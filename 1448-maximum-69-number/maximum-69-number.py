class Solution:
    def maximum69Number (self, num: int) -> int:
        maximum = num
        length = len(str(num))

        for i in range(length-1,-1,-1):
            temp = num
            if str(num)[length-i-1] == '6':
                temp = temp+(10**i)*3
            
            if temp > maximum:
                maximum = temp
        
        return maximum
            
            