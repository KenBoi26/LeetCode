class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            count++;

            for(int i:adj[top]){
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }

        return numCourses == count;
    }
};