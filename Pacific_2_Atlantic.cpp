class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int x,int y,vector<vector<int>>& heights,vector<vector<bool>> &visited){
        visited[x][y]=1;

        for(auto &d:dir){
            int nx=x+d[0];
            int ny=y+d[1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && heights[nx][ny]>=heights[x][y] && !visited[nx][ny]){
                dfs(nx,ny,heights,visited);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pac(n,vector<bool>(m,0));
        vector<vector<bool>> atl(n,vector<bool>(m,0));
          
        // Pacific:
        for(int i=0;i<n;i++){
            dfs(i,0,heights,pac);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,heights,pac);
        }

        //Atlantic:
        for(int i=0;i<n;i++) dfs(i,m-1,heights,atl);
        for(int j=0;j<m;j++) dfs(n-1,j,heights,atl);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j] ){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};