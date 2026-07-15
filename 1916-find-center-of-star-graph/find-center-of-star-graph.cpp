class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<vector<int>> adjList(edges.size()+2);

        for(auto &i:edges){
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }

        int maxi = 0;

        for(int i=0; i<adjList.size(); i++){
            if(adjList[i].size() > adjList[maxi].size()) maxi = i;
        }

        return maxi;
    }
};