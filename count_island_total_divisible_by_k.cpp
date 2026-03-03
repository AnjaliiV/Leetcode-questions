class Solution {
public:
int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    long long dfs(int x,int y,vector<vector<int>>& grid,vector<vector<bool>> &visited){
        if(x<0 || x>=n || y<0 || y>=m) return 0;
        if(grid[x][y]==0 || visited[x][y]) return 0;
        visited[x][y]=1;
        long long sum=grid[x][y];
        for(auto &d:dir){
            int nx=x+d[0];
            int ny=y+d[1];
            sum+=dfs(nx,ny,grid,visited);
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]!=0){
                    long long sum=dfs(i,j,grid,visited);
                   if(sum%k==0) count++;
                }
            }
        }
        return count;
        
    }
};