class Solution {
public:

    bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int source, int destination){
        if(source == destination) return true;
        visited[source] = true;

        for(int i:adj[source]){
            if(!visited[i]){
                if(dfs(adj, visited, i, destination)) return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> adjList(n);

        for(int i=0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n, false);



        return dfs(adjList, visited, source, destination);

        
    }
};