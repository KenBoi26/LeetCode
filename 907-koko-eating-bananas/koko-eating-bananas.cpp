class Solution {
public:

    long long maxTime(vector<int> &piles, int speed){
        long long time=0;
        for(int i=0; i<piles.size(); i++){
            time += ceil(double(piles[i])/double(speed));
        }

        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max = -1;
        for(auto i:piles){
            if(i > max) max = i;
        }

        int start = 1;
        int end = max;
        int mid,fina;
        long long time;

        while(start <= end){
            mid = (start+end)/2;
            time = maxTime(piles, mid);
            if(time <= h){
                fina = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        return fina;
    }
};