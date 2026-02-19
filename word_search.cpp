class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(vector<vector<char>>& board, string word,int x,int y,int i,vector<vector<bool>> &visited){
        if(i==word.size()) return 1;
        if(x<0 || x>=n || y<0 || y>=m) return 0;
        if(board[x][y]!=word[i] || visited[x][y]) return 0;

        visited[x][y]=1;

        for(auto &d:dir){
            int nx=x+d[0];
            int ny=y+d[1];
            // if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]==word[i+1] && !visited[nx][ny]){
            if(dfs(board,word,nx,ny,i+1,visited)){
                return true;
            }
        }
        visited[x][y]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         n=board.size();
         m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && !visited[i][j]){
                    if(dfs(board,word,i,j,0,visited))
                    return true;
                }
            }
        }
        return false;     
    }
};