class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current = 0;
        int total = 0;
        int start = 0;

        for(int i=0; i<gas.size(); i++){
            int net = gas[i]-cost[i];
            current += net;
            total += net;
            
            if(current < 0){
                start = i+1;
                current = 0;
            }
        }

        if(total < 0) return -1;
        return start;
    }
};