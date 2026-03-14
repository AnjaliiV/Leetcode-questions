class Solution {
public:
int helper(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    int n=matrix.size();

    // Base Case:
    if(j<0 || j>=n) return INT_MAX;
    if(i==n-1) return matrix[i][j];
    if (dp[i][j] != INT_MIN) return dp[i][j];
    int down=helper(i+1,j,matrix,dp);
    int leftdiag=helper(i+1,j-1,matrix,dp);
    int rightdiag=helper(i+1,j+1,matrix,dp);
    return dp[i][j]=matrix[i][j]+ min(down,min(leftdiag,rightdiag));


}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        for(int j=0;j<n;j++){
            mini=min(mini,helper(0,j,matrix,dp));
        }
        return mini;
    }
};
