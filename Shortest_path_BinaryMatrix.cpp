class Solution {
public:
    int n;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int bfs(vector<vector<int>> &grid){
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        visited[0][0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        int count=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1 && y==n-1) return count;
                 for(auto d:dir){
                     int nx=x+d[0];
                     int ny=y+d[1];
     
                     if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0 && !visited[nx][ny]){
                         q.push({nx,ny});
                         visited[nx][ny]=1;
                     }
                }
            }
             count++;

        }
        
        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         n=grid.size();
        return bfs(grid);
    }
};