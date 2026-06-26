class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left = 0;
        int right = mat[0].size()-1;

        while(left <= right){
            int mid = left+(right-left)/2;

            int max = 0;

            for(int i=1; i<mat.size(); i++){
                if(mat[i][mid] > mat[max][mid]) max = i;
            }

            int leftValue = -1;
            if(mid > 0) leftValue = mat[max][mid-1];

            int rightValue = -1;
            if(mid < mat[0].size()-1) rightValue = mat[max][mid+1];

            if(mat[max][mid] >= leftValue && mat[max][mid] >= rightValue) return {max, mid};

            if(mat[max][mid] < leftValue){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return {-1,-1};
    }
};