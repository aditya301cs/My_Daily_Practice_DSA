class Solution {
public:
    // Helper function to perform Depth First Search (DFS)
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Check for out-of-bound indices or water cells ('0')
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }

        // Mark the cell as visited by setting it to '0'
        grid[i][j] = '0';

        // Recursively visit all 4 adjacent cells
        dfs(grid, i + 1, j);  // Down
        dfs(grid, i - 1, j);  // Up
        dfs(grid, i, j + 1);  // Right
        dfs(grid, i, j - 1);  // Left
    }

    // Function to count the number of islands
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;  // Initialize the count of islands to 0

        // Traverse each cell in the grid
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                // If the cell is part of an island ('1'), perform DFS
                if (grid[i][j] == '1') {
                    ++numIslands;  // Increment the island count
                    dfs(grid, i, j);  // Mark the entire island as visited
                }
            }
        }

        return numIslands;  // Return the total number of islands
    }
};
