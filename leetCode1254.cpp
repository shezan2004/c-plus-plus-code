class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        auto flood = [&](int si, int sj) {
            queue<pair<int,int>> q;
            q.push({si, sj});
            grid[si][sj] = 1;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        };

        // Remove every land region touching the border
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) flood(i, 0);
            if (grid[i][n-1] == 0) flood(i, n-1);
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0) flood(0, j);
            if (grid[m-1][j] == 0) flood(m-1, j);
        }

        // Remaining land regions are closed islands
        int count = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    flood(i, j);
                }
            }
        }
        return count;
    }
};