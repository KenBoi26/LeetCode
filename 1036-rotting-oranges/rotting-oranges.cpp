class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    count++;
                }
            }
        }

        if(count == 0) return 0;
        int minutes = 0;
        int changedRow[4] = {-1, 1, 0, 0};
        int changedCol[4] = {0, 0, -1, 1};

        while(!q.empty()){
            int size = q.size();
            bool rotten = false;

            for(int i=0; i<size; i++){
                pair<int,int>current = q.front();
                q.pop();
                int row = current.first;
                int col = current.second;
                

                for(int j=0; j<4; j++){
                    int newRow = row + changedRow[j];
                    int newCol = col + changedCol[j];

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1){
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});

                        count--;
                        rotten = true;
                    }
                }
            }
            if(rotten) minutes++;
        }

        if(count == 0) return minutes;
        return -1;

    }
};