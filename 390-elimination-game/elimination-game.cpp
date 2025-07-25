class Solution {
public:
    int helper(int n, bool direction){
        if(n==1) return 1;

        if(n%2 == 1 || direction){
            return 2*helper(n/2, !direction);
        }else{
            return 2*helper(n/2, !direction) - 1;
        }
    }

    int lastRemaining(int n) {
        return helper(n, true);
    }
};