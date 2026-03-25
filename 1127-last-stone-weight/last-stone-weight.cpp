class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i:stones){
            pq.push(i);
        }

        while(pq.size() > 1){
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();

            pq.push(num1-num2);
        }

        if(pq.size() == 1) return pq.top();

        return 0;
    }
};