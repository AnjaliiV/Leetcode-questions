class Solution {
  public:
  vector<vector<int>> dir={{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        KnightPos[0]--;
        KnightPos[1]--;
        TargetPos[0]--;
        TargetPos[1]--;
        if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1]) return 0;
        vector<vector<bool>> board(N,vector<bool>(N,0));
        queue<pair<int,int>> q;
        board[KnightPos[0]][KnightPos[1]]=1;
        q.push({KnightPos[0],KnightPos[1]});
        
        int steps=0;
        while(!q.empty()){
            int count=q.size();
            //Level based traversal:
            while(count--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
            
                for(auto &d:dir){
                    int nx=x+d[0];
                    int ny=y+d[1];
                     if(nx==TargetPos[0] &&ny==TargetPos[1]) return steps+1;
                     if(nx>=0 && nx<N && ny>=0 && ny<N && !board[nx][ny]){
                         board[nx][ny]=1;
                         q.push({nx,ny});
                     }
                }
            }
            steps++;
        }
        return -1;
    }
};