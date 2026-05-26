class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        
        candidates.sort()
        
        result = []

        def dfs(index, current, total):
            if target == total:
                result.append(current.copy())
                return
            
            if total > target or index >= len(candidates):
                return
            
            current.append(candidates[index])
            dfs(index+1, current, total + candidates[index])
            current.pop()

            while index+1 < len(candidates) and candidates[index] == candidates[index+1]:
                index += 1
            
            dfs(index+1, current, total)
        
        dfs(0,[],0)
        return result