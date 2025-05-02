class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int startRow = 0;
        int startCol = 0;
        int endRow = matrix.size() - 1;
        int endCol = matrix[0].size() - 1;

        while (startRow <= endRow && startCol <= endCol) {
            // Traverse from left to right
            for (int i = startCol; i <= endCol; i++) {
                result.push_back(matrix[startRow][i]);
            }

            // Traverse from top to bottom
            for (int i = startRow + 1; i <= endRow; i++) {
                result.push_back(matrix[i][endCol]);
            }

            // Traverse from right to left
            for (int i = endCol - 1; i >= startCol; i--) {
                if (startRow == endRow) break; // Avoid duplicate row
                result.push_back(matrix[endRow][i]);
            }

            // Traverse from bottom to top
            for (int i = endRow - 1; i >= startRow + 1; i--) {
                if (startCol == endCol) break; // Avoid duplicate column
                result.push_back(matrix[i][startCol]);
            }

            // Move to the inner sub-matrix
            startRow++;
            startCol++;
            endRow--;
            endCol--;
        }

        return result;
    }
};
