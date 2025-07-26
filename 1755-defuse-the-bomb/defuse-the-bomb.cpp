class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> sum_arr(code.size());
        for(int i=0; i<code.size(); i++){
            if(k>=0){
                for(int j = 1; j<=k; j++){
                    sum_arr[i] += code[(i + j)%code.size()];
                }
            }else{
                for(int j = 1; j<=-k; j++){
                    sum_arr[i] += code[(i - j+ code.size())%code.size()];
                }
            }
            cout << "=" << sum_arr[i] << endl;

        }

        return sum_arr;
    }
};