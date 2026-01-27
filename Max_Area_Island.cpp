class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        // base cases
        if (x < 0 || x >= m || y < 0 || y >= n) return 0;
        if (grid[x][y] == 0 || visited[x][y]) return 0;

        visited[x][y] = true;   // mark visited

        int area = 1; // count current cell

        for (auto &d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];
            area += dfs(nx, ny, grid, visited);
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    maxArea = max(maxArea, dfs(i, j, grid, visited));
                }
            }
        }

        return maxArea;
    }
};