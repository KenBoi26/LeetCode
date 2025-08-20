class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if(numRows == 0):
            return []
        triangle = [[1],[1,1]]

        for i in range(2,numRows):
            temp = [triangle[i-1][0]]
            for j in range(1,len(triangle[i-1])):
                temp.append(triangle[i-1][j]+triangle[i-1][j-1])
            temp.append(triangle[i-1][-1])
            triangle.append(temp)



        return triangle[0:numRows]
