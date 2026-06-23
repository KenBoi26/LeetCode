class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;

        if(num == 0 || num == 1) return true;

        while(left<right){
            long long mid = left+(right-left)/2;
            if(mid*mid == num) return true;
            else if(mid*mid < num) left = mid+1;
            else right = mid;
        }

        return false;
    }
};