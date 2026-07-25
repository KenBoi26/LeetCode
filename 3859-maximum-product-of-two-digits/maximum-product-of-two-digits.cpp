class Solution {
public:
    int maxProduct(int n) {
        int max_index = 0;
        vector<int> number;

        while(n>0){
            number.push_back(n%10);
            n/=10;
        }

        for(int i=0; i<number.size(); i++){
            if(number[i] >= number[max_index]){
                max_index = i;
            }
        }

        int second_max = (max_index == 0) ? 1 : 0;

        for(int i=0; i<number.size(); i++){
            if(number[i] >= number[second_max] && i != max_index){
                second_max = i;
            }
        }

        return number[second_max] * number[max_index];

    }
};