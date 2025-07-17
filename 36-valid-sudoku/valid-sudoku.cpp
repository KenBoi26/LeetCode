class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9);
        vector<set<char>> columns(9);
        vector<set<char>> boxes(9);

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char current_char = board[i][j];

                if(current_char == '.'){
                    continue;
                }

                if(rows[i].count(current_char)){
                    return false;
                }
                rows[i].insert(current_char);

                if(columns[j].count(current_char)){
                    return false;
                }
                columns[j].insert(current_char);

                int box_index = (i/3)*3 + (j/3);
                if(boxes[box_index].count(current_char)){
                    return false;
                }

                boxes[box_index].insert(current_char); 
            }
        }

        return true;
    }
};