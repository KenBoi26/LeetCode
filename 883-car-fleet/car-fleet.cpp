class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> complete(position.size());

        for(int i=0; i<position.size(); i++){
            complete[i] = {position[i],speed[i]};
        }

        sort(complete.rbegin(), complete.rend());


        stack<float> st;

        int distance = target - complete[0].first;

        float time = (float)distance/(float)complete[0].second;

        st.push(time);

        for(int i=1; i<complete.size(); i++){
            int distance = target - complete[i].first;
            float time = (float)distance/(float)complete[i].second;

            cout << time << endl;

            if(time > st.top()) st.push(time);

        }

        return st.size();


    }
};
