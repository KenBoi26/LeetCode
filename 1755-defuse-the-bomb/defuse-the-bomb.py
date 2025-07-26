class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        result = [0] * n

        for i in range(n):
            if(k >= 0):
                for j in range(1,k+1):
                    result[i] += code[(i+j)%n]
            else:
                for j in range(1, -k + 1):
                    result[i] += code[(i-j+n)%n]
        
        return result
        