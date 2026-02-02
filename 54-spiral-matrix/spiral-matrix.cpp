class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rightColumn = matrix[0].size()-1;
        int leftColumn = 0;
        int bottomRow = matrix.size()-1;
        int topRow = 0;
        vector<int> boundary;

        while(topRow <= bottomRow && leftColumn <= rightColumn){
            for(int i=leftColumn; i<=rightColumn; i++){
                boundary.push_back(matrix[topRow][i]);
            }
            topRow++;

            for(int i=topRow; i<=bottomRow; i++){
                boundary.push_back(matrix[i][rightColumn]);
            }
            rightColumn--;

            if(topRow<=bottomRow){
                for(int i=rightColumn; i>=leftColumn; i--){
                    boundary.push_back(matrix[bottomRow][i]);
                }
                bottomRow--;
            }
            
            if(leftColumn <= rightColumn){
                for(int i=bottomRow; i>= topRow; i--){
                    boundary.push_back(matrix[i][leftColumn]);
                }
                leftColumn++;
            }
        }

        return boundary;
    }
};