class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();      // Number of rows in original matrix
        int n = mat[0].size();   // Number of columns in original matrix

        // Check if reshaping is possible
        if (m * n != r * c) {
            return mat; // Return the original matrix if reshaping isn't possible
        }

        // Create the reshaped matrix
        vector<vector<int>> reshaped(r, vector<int>(c));

        // Fill the reshaped matrix
        for (int i = 0; i < m * n; i++) {
            reshaped[i / c][i % c] = mat[i / n][i % n];
        }

        return reshaped;
    }
};
