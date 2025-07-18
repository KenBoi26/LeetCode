class Solution:
    def backtrack(self, result: list, current: str, open_count: int, closed_count: int,n: int):
        if len(current) == 2*n:
            result.append(current)
            return
        
        if open_count < n:
            self.backtrack(result, current+"(", open_count+1, closed_count, n)
        
        if closed_count < open_count:
            self.backtrack(result, current+")", open_count, closed_count+1, n)
    

    def generateParenthesis(self, n: int) -> List[str]:
        result=[]
        self.backtrack(result, "", 0, 0, n)

        return result
        