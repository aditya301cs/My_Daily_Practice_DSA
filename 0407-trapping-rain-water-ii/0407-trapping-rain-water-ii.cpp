#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        // Min-heap: {height, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push all boundary cells into the heap
        for (int i = 0; i < m; i++) {
            minHeap.push({heightMap[i][0], i, 0});
            minHeap.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 0; j < n; j++) {
            minHeap.push({heightMap[0][j], 0, j});
            minHeap.push({heightMap[m-1][j], m-1, j});
            visited[0][j] = visited[m-1][j] = true;
        }

        int trappedWater = 0;
        vector<int> dirs = {0, 1, 0, -1, 0};

        while (!minHeap.empty()) {
            auto cell = minHeap.top(); minHeap.pop();
            int h = cell[0], x = cell[1], y = cell[2];

            // Explore neighbors
            for (int d = 0; d < 4; d++) {
                int nx = x + dirs[d], ny = y + dirs[d+1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;
                visited[nx][ny] = true;

                // If neighbor is lower, water can be trapped
                trappedWater += max(0, h - heightMap[nx][ny]);

                // Push updated boundary
                minHeap.push({max(heightMap[nx][ny], h), nx, ny});
            }
        }

        return trappedWater;
    }
};
