class Solution {
public:
    int mySqrt(int x) {
        long long left = 0;
        long long right = x;

        while(left < right){
            long long mid = left+(right-left)/2;

            if(mid*mid >= x) right = mid;
            else left = mid+1;
        }

        if(right*right > x) return right-1;
        return right;
    }
};