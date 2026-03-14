/*class Solution {
public:
// vector<vector<int>> &dp
    int dp[201][201];
    int n;
    int helper(int i, int j, vector<vector<int>>& grid){
       // Base Case:
       if(i==n-1) return grid[i][j];
   
       // If value already computed, return the calculated value:
       if(dp[i][j] != -1) return dp[i][j];
   
       // choosing recursively the next min column:
       int ans= INT_MAX;
       for(int nextcol=0; nextcol<n; nextcol++){
           // the next col should not be equal to the current column:
           if(nextcol != j){
              ans =min(ans,helper(i+1,nextcol,grid));
           }
       }
          return dp[i][j] = ans+ grid[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n=grid.size();

        // vector<vector<int>> dp(n,vector<int>(n,-1));
        memset(dp,-1,sizeof(dp));

        // choosing the minimum from each col
        int res= INT_MAX;
        for(int j=0; j<n ;j++){
             res=min(res,helper(0,j,grid));
        }
        return res;
        
    }
};*/


class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
        int n=grid.size();
        //Base Case:
        if(j<0 || j>n) return INT_MAX;
        if(i==n-1) return grid[i][j];

        if(dp[i][j]!=INT_MIN) return dp[i][j];

        int mini=INT_MAX;
        for(int k=0;k<n;k++){
            if(k==j) continue;
            int move=helper(i+1,k,grid,dp);
            mini=min(move,mini);
        }
        return dp[i][j]=grid[i][j]+mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int mini=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        for(int j=0;j<n;j++){
            mini=min(mini,helper(0,j,grid,dp));

        }
        return mini;
    }
};
