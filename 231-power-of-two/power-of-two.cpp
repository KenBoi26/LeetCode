class Solution {
public:
    bool is_pow(int n){
        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }

        if(n%2 == 0){
            return is_pow(n/2);
        }

        return false;
    }

    bool isPowerOfTwo(int n) {

        return is_pow(n);
    }
};