class Solution {
public:

    bool dfs(int row, int column, vector<vector<int>> &grid, vector<vector<int>> &visited, int cycle){
        if(row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size()) return false;

        if(grid[row][column] == 1 || visited[row][column] == cycle) return false;

        if(row == grid.size()-1 && grid[row][column] == 0) return true;

        visited[row][column] = cycle;

        return dfs(row+1, column, grid, visited, cycle) || dfs(row-1, column, grid, visited, cycle) || dfs(row, column+1, grid, visited, cycle) || dfs(row, column-1, grid, visited, cycle);
        
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        vector<vector<int>> grid(row, vector<int>(col, 0));

        int count = 0;
        vector<vector<int>> visited(row, vector<int>(col, false));        
        int cycle = 1;

        for(auto i:cells){
            grid[i[0]-1][i[1]-1] = 1;
            bool found = false;

            

            for(int j=0; j<col; j++){
                if(grid[0][j] == 0){
                    
                    if(dfs(0, j, grid, visited, cycle)){
                        found = true;
                        break;
                    }
                }
            }
            cycle++;

            if(!found) return count;
            count++;
        }

        return count;
    }
};