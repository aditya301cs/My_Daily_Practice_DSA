class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower,
                                          vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> mat(2, vector<int>(n));
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                mat[0][i] = 1;
                mat[1][i] = 1;
                upper--;
                lower--;
                colsum[i] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            if (upper != 0 && colsum[i] != 0) {
                mat[0][i] = 1;
                colsum[i]--;
                upper--;
            }
        }

        for (int i = 0; i < n; i++) {
            if (lower != 0 && colsum[i] != 0) {
                mat[1][i] = 1;
                colsum[i]--;
                lower--;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += colsum[i];
        }
        if (upper != 0 || lower != 0 || sum != 0) {
            return {};
        }
        return mat;
    }
};