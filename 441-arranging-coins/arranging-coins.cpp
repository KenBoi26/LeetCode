class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0;
        int right = n;

        if (n==1) return 1;

        while(left < right){
            long long mid = left+(right-left)/2;
            long long AP = (mid*(mid+1))/2;
            if(AP == n) return mid;
            if(AP > n) right = mid;
            else left = mid + 1;
        }

        return right-1;
    }
};