class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(int x,int y,vector<vector<int>>& grid,vector<vector<bool>> &visited){
        if(x<0 || x>=n || y<0 || y>=m) return 0;
        if(grid[x][y]==0 || visited[x][y]) return 0;
        visited[x][y]=1;
        int fish=grid[x][y];
        for(auto&d:dir){
            int nx=x+d[0];
            int ny=y+d[1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!=0 && !visited[nx][ny]){
                fish+=dfs(nx,ny,grid,visited);
            }
        }
        return fish;

    }


    int findMaxFish(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int maxfish=0;
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && !visited[i][j]){
                    int fish=dfs(i,j,grid,visited);
                    maxfish=max(fish,maxfish);
                }
            }
        }
        return maxfish;
    }
};