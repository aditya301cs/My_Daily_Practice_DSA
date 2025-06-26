class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int freshCount = 0;

        // Step 1: Add all rotten oranges to the queue and count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // If no fresh orange, return 0
        if (freshCount == 0) return 0;

        int minutes = 0;
        
        // Direction vectors: DOWN, LEFT, RIGHT, UP
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};

        // BFS to rot fresh oranges
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int i = 0; i < size; i++) {
                pair<int, int> front = q.front(); q.pop();
                int x = front.first;
                int y = front.second;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;  // rot it
                        freshCount--;
                        q.push({nx, ny});
                        rotted = true;
                    }
                }
            }

            if (rotted) minutes++;  // only count minute if something rotted this round
        }

        // If freshCount == 0, all oranges rotted; otherwise, return -1
        return freshCount == 0 ? minutes : -1;
    }
};
