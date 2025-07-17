class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows=[[] for i in range(9)]
        columns=[[] for i in range(9)]
        boxes=[[] for i in range(9)]

        for i in range(9):
            for j in range(9):
                current_char = board[i][j]

                if current_char == '.':
                    continue

                if rows[i].count(current_char):
                    return False
                
                rows[i].append(current_char)

                if columns[j].count(current_char):
                    return False
                
                columns[j].append(current_char)

                index = (i//3)*3 + j//3
                if boxes[index].count(current_char):
                    return False
                
                boxes[index].append(current_char)
        

        return True