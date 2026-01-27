class Solution {
public:
    int m,n;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int x,int y,vector<vector<char>>& grid,vector<vector<bool>> &visited,int px,int py){
        visited[x][y]=1;

        for(auto &d:dir){
            int nx=x+d[0];
            int ny=y+d[1];
            if(nx<0 || nx>m-1 || ny<0 || ny>n-1 || grid[nx][ny]!=grid[x][y] || px==nx && py==ny) continue;
            else if(visited[nx][ny]) return true;
            if(!visited[nx][ny]){
              if(dfs(nx,ny,grid,visited,x,y)){
                return true;
              }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        int px,py;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                   if(dfs(i,j,grid,visited,-1,-1))
                          return true;
                }
            }
        }
        return false;
    }
};