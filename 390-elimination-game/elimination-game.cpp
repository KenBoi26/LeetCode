class Solution {
public:
    int lastRemaining(int n) {
        int currL = n;
        int diff = 1;
        int l =1;
        int r = n;
        bool lefttoright  = true;
        while(l<r){
            if(currL%2==1){
                l  = l+diff;
                r= r-diff;
            }
            else{
                if(lefttoright){
                    l = l+diff;
                }
                else{
                    r = r-diff;
                }
            }
            diff*=2;
            currL/=2;
            lefttoright= !lefttoright;
        }
        return l;
    }
};