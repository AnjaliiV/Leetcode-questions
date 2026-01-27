class Solution {
public:
    int m,n;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int x,int y,vector<vector<char>>& grid,vector<vector<bool>>& visited){
        //BAse case:
        if(x<0 || x>m-1 || y<0 || y>n-1) return ;
        if(grid[x][y]=='0' || visited[x][y])  return ;
        visited[x][y]=1;
        for(auto &d:dir){
            int nx=x+d[0];
            int ny=y+d[1];
            dfs(nx,ny,grid,visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&& !visited[i][j]){
                dfs(i,j,grid,visited);
                ans++;
                }
            }
        }
        return ans;
        
    }
};