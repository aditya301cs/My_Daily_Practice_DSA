class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // To create a mxn normal matrix 
      //vector<vector<int>> matrix(rows, vector<int>(cols));

        vector<vector<int>> result(n, vector<int>(m));  //n*m for transpose matrix
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
};