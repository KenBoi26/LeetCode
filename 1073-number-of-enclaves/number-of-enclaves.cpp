class Solution {
public:

    void dfs(vector<vector<int>> &grid, int r, int c, int &count){
        if(r<0 || r>=grid.size() || c<0 || c >= grid[0].size()) return;
        if(grid[r][c] != 1) return;

        if(grid[r][c] == 1){
            grid[r][c] = 2;
            count++;
        }

        dfs(grid, r-1, c, count);
        dfs(grid, r+1, c, count);
        dfs(grid, r, c-1, count);
        dfs(grid, r, c+1, count);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for(int i=0; i<n; i++){
            if(grid[i][0] == 1) dfs(grid, i, 0, count);
            if(grid[i][m-1] == 1) dfs(grid, i, m-1, count);
        }

        for(int i=0; i<m; i++){
            if(grid[0][i] == 1) dfs(grid, 0, i, count);
            if(grid[n-1][i] == 1) dfs(grid, n-1, i, count);
        }

        count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, count);
                }
            }
        }

        return count;
    }
};