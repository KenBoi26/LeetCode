class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])

        start_row = 0
        end_row = n
        

        while(start_row < end_row):
            mid_row = (start_row + end_row)//2
            if target < matrix[mid_row][0]:
                end_row = mid_row
            elif target > matrix[mid_row][-1]:
                start_row = mid_row + 1
            else:
                l = 0
                r = m
                while(l<r):
                    mid = (l+r)//2
                    if matrix[mid_row][mid] == target:
                        return True
                    elif matrix[mid_row][mid] > target:
                        r = mid
                    else:
                        l = mid+1
                
                return False
        
        return False