class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int fresh = 0, time = 0;

        //Push all rotten oranges into queue
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    visited[i][j] = true;
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        //directions up,down,right,left where we can rot the fresh oranges
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        // BFS
        while(!q.empty() && fresh > 0){
            int len = q.size();
            time++;

            for(int i = 0; i < len; i++){
                auto [x, y] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int nx = x + dir[j][0];
                    int ny = y + dir[j][1];

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n &&
                       !visited[nx][ny] && grid[nx][ny] == 1){
                        
                        visited[nx][ny] = true;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return fresh == 0 ? time : -1;
    }
};
