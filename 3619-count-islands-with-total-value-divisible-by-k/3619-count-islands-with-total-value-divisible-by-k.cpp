class Solution {
public:
    int getIsland(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited){
        visited[row][col] = true;
        long long value = grid[row][col];

        // Check all 4 neighbors
        if (row - 1 >= 0 && !visited[row - 1][col] && grid[row - 1][col] > 0) {
            value += getIsland(grid, row - 1, col, visited);
        }
        if (row + 1 < grid.size() && !visited[row + 1][col] && grid[row + 1][col] > 0) {
            value += getIsland(grid, row + 1, col, visited);
        }
        if (col - 1 >= 0 && !visited[row][col - 1] && grid[row][col - 1] > 0) {
            value += getIsland(grid, row, col - 1, visited);
        }
        if (col + 1 < grid[0].size() && !visited[row][col + 1] && grid[row][col + 1] > 0) {
            value += getIsland(grid, row, col + 1, visited);
        }
        return value;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        // vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if (!visited[i][j] && grid[i][j] > 0) {
                    int total = getIsland(grid, i, j, visited);
                    if (total % k == 0) {
                        count++;
                    }
                }
            }
        }   
        return count;
    }
};