class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rightColumn = n-1;
        int leftColumn = 0;
        int bottomRow = n-1;
        int topRow = 0;
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int index = 1;

        while(topRow <= bottomRow && leftColumn <= rightColumn){
            vector<int> temp;
            for(int i=leftColumn; i<=rightColumn; i++){
                matrix[topRow][i] = index++;
            }
            topRow++;

            for(int i=topRow; i<=bottomRow; i++){
                matrix[i][rightColumn] = index++;
            }
            rightColumn--;

            if(topRow<=bottomRow){
                for(int i=rightColumn; i>=leftColumn; i--){
                    matrix[bottomRow][i] = index++;
                }
                bottomRow--;
            }
            
            if(leftColumn <= rightColumn){
                for(int i=bottomRow; i>= topRow; i--){
                    matrix[i][leftColumn] = index++;
                }
                leftColumn++;
            }

        }

        return matrix;
    }
};