class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        def is_pow(num):
            if num <= 0:
                return False
            
            if num == 1:
                return True
            
            if num%2 == 0:
                return is_pow(num//2)
            
            return False

        return is_pow(n)