class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> complete(position.size());

        for(int i=0; i<position.size(); i++){
            complete[i] = {position[i],speed[i]};
        }

        sort(complete.begin(), complete.end());


        stack<float> st;

        int distance = target - complete[complete.size()-1].first;

        float time = (float)distance/(float)complete[complete.size()-1].second;

        st.push(time);

        for(int i=complete.size()-2; i>=0; i--){
            int distance = target - complete[i].first;
            float time = (float)distance/(float)complete[i].second;

            if(time > st.top()) st.push(time);

        }

        return st.size();


    }
};
