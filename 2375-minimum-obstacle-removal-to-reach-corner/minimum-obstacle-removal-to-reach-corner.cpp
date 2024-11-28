class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        dist[0][0] = 0;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dir[k][0], ny = y + dir[k][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int newDist = dist[x][y] + grid[nx][ny];
                if (newDist < dist[nx][ny]) {
                    dist[nx][ny] = newDist;
                    if (grid[nx][ny] == 1) {
                        dq.push_back({nx, ny});
                    } else {
                        dq.push_front({nx, ny}); 
                    }
                }
            }
        }
        
        // Return minimum distance to bottom-right cell
        return dist[m - 1][n - 1];
    }
};