class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int x,int y,vector<vector<int>>& grid2,vector<vector<int>>& grid1,vector<vector<bool>> &visited){
        if(x<0 || y<0 || x>=n || y>=m) return 0;
        if(grid2[x][y]==0 || visited[x][y]) return 0;

        visited[x][y]=1;

        bool iSub=(grid1[x][y]==1); //main check
        for(auto &d:dir){
            int nx=x+d[0];
            int ny=y+d[1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid2[nx][ny]==1 && !visited[nx][ny] ){
                iSub &= dfs(nx,ny,grid2,grid1,visited);

            }
        }
        return iSub;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) { 
        n=grid1.size();
        m=grid1[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && !visited[i][j]){
                    if(dfs(i,j,grid2,grid1,visited))
                    count++;
                }
            }
        }
        return count;
    }
};