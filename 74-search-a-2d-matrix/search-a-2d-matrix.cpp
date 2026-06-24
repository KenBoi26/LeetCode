class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int start_row = 0;
        int end_row = n;

        while (start_row < end_row) {
            int mid_row = (start_row + end_row) / 2;

            if (target < matrix[mid_row][0]) {
                end_row = mid_row;
            } else if (target > matrix[mid_row][m - 1]) {
                start_row = mid_row + 1;
            } else {
                int l = 0;
                int r = m;

                while (l < r) {
                    int mid = (l + r) / 2;

                    if (matrix[mid_row][mid] == target) {
                        return true;
                    } else if (matrix[mid_row][mid] > target) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }

                return false;
            }
        }

        return false;
    }
};