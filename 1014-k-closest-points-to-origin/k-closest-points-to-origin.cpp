class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pair<double,vector<int>>> pq;

        for(int i=0; i<points.size(); i++){
            double distance = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);

            pq.push({distance,points[i]});

            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};