class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int x,int y,vector<vector<int>>& grid,vector<vector<bool>> &visited){
        if(x<0 ||x>=n || y<0 || y>=m) return;
        if(grid[x][y]==0 || visited[x][y]) return;
        visited[x][y]=1;
        for(auto &d:dir){
            int nx=x+d[0];
            int ny=y+d[1];
            dfs(nx,ny,grid,visited);
            // if(nx==n-1 || ny ==m-1) continue;

        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int count=0;
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( i==n-1 || j==m-1 || i==0 || j==0 && !visited[i][j] && grid[i][j]==1 ){
                    // if(){
                    dfs(i,j,grid,visited);
                    // }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    count++;
                }
            }
        }
        return count;
        
    }
};
