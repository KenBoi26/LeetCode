class Solution {
public:
    int find_max(vector<int> piles){
        int mx = -1;
        for(auto i : piles){
            if(i > mx){
                mx = i;
            }
        }

        return mx;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = find_max(piles);

        int l=1,r=mx;

        int ans = r;

        while(l<=r){
            int k = (l+r)/2;
            long long sm = 0;
            for(auto i : piles){
                sm += (i+k-1)/k;
            }


            if(sm <= h){
                ans=k;
                r = k-1;
            }else{
                l = k+1;
            }
        }

        return ans;

        

    }
};