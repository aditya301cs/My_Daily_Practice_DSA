class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();    // Number of rows
        int n = matrix[0].size(); // Number of columns
        bool shouldFillFirstRow = false, shouldFillFirstCol = false;

        // Step 1: Check if the first row should be filled with zeroes
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                shouldFillFirstRow = true;
                break;
            }
        }

        // Step 2: Check if the first column should be filled with zeroes
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                shouldFillFirstCol = true;
                break;
            }
        }

        // Step 3: Mark rows and columns that need to be zeroed
        // We use the first row and first column as markers
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark the row
                    matrix[0][j] = 0; // Mark the column
                }
            }
        }

        // Step 4: Set zeroes based on markers
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Zero out the first row if needed
        if (shouldFillFirstRow) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // Step 6: Zero out the first column if needed
        if (shouldFillFirstCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
