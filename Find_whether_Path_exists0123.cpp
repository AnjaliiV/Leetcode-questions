
class Solution {
  public:
    // Function to find whether a path exists from the source to destination.
    int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool is_Possible(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
       vector<vector<bool>> visited(n,vector<bool>(m,0));
       queue<pair<int,int>> q;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==1){
                   visited[i][j]=1;
                   q.push({i,j});
               }
           }
       }
       while(!q.empty()){
           int x=q.front().first;
           int y=q.front().second;
           q.pop();
           for(auto &d:dir){
               int nx=x+d[0];
               int ny=y+d[1];
               if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny]){
                   if(grid[nx][ny]==3){
                        visited[nx][ny]=1;
                        q.push({nx,ny});
                   }
                    if(grid[nx][ny]==2)
                    return true;
                }
            }
       }
       return false;
    }
};