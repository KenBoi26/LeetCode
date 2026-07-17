class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) count++;
            }
        }

        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,-1}, {0,1}};
        int time = 0;

        while(!q.empty()){
            int size = q.size();
            bool rotten = false;

            for(int i=0; i<size; i++){
                auto [r, c] = q.front();
                q.pop();

                for(auto i:directions){
                    int new_row = r + i.first;
                    int new_column = c + i.second;

                    if(new_row >= 0 && new_row < n && new_column >= 0 && new_column < m && grid[new_row][new_column] == 1){
                        grid[new_row][new_column] = 2;
                        q.push({new_row, new_column});
                        rotten = true;
                        count--;
                    }
                }
            }

            if(rotten) time++;
        }

        if(count == 0) return time;
        return -1;

    }
};