class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0)); // Initialize n x n matrix with 0s
        int num = 1; // Number to insert
        int startRow = 0, startCol = 0;
        int endRow = n - 1, endCol = n - 1;

        while (startRow <= endRow && startCol <= endCol) {
            // Traverse from left to right
            for (int i = startCol; i <= endCol; i++) {
                matrix[startRow][i] = num++;
            }
            startRow++; // Move row boundary down

            // Traverse from top to bottom
            for (int i = startRow; i <= endRow; i++) {
                matrix[i][endCol] = num++;
            }
            endCol--; // Move column boundary left

            // Traverse from right to left
            if (startRow <= endRow) {
                for (int i = endCol; i >= startCol; i--) {
                    matrix[endRow][i] = num++;
                }
                endRow--; // Move row boundary up
            }

            // Traverse from bottom to top
            if (startCol <= endCol) {
                for (int i = endRow; i >= startRow; i--) {
                    matrix[i][startCol] = num++;
                }
                startCol++; // Move column boundary right
            }
        }

        return matrix;
    }
};
