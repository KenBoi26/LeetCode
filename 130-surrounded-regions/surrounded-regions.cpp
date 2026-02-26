class Solution {
public:

    void dfs(int r, int c, vector<vector<char>> &board){
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'O') return;

        board[r][c] = 'T';

        dfs(r+1, c, board);
        dfs(r-1, c, board);
        dfs(r, c+1, board);
        dfs(r, c-1, board);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            dfs(i, 0, board);
            dfs(i, m-1, board);
        }

        for(int i=0; i<m; i++){
            dfs(0, i, board);
            dfs(n-1, i, board);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};