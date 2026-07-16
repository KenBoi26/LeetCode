class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> result(n, vector<int>(m, -1));
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j] == 1){
                    q.push({i,j});
                    result[i][j] = 0;
                }
            }
        }

        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(auto dr:directions){
                int new_row = r + dr.first;
                int new_column = c + dr.second;

                if(new_row >= 0 && new_row < n && new_column >= 0 && new_column < m){
                    if(result[new_row][new_column] == -1){
                        result[new_row][new_column] = result[r][c] + 1;
                        q.push({new_row, new_column});
                    }
                }
            }
        }

        return result;
    }
};