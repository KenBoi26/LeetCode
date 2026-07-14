class Solution {
public:

    vector<vector<int>> result;

    void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> temp, int node){
        visited[node] = true;
        temp.push_back(node);

        if(node == adj.size()-1) result.push_back(temp);

        for(int i:adj[node]){
            if(!visited[i]){
                dfs(adj, visited, temp, i);
                visited[i] = false;
            }
        }

        temp.pop_back();
    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<int> temp;

        dfs(graph, visited, temp, 0);

        return result;
    }
};