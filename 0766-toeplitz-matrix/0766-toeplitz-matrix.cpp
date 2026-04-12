class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int m = mat.size();  // row
        int n = mat[0].size(); //column
        
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(mat[i][j] != mat[i-1][j-1])
                    return false;
            }
        }
        return true;
    }
};