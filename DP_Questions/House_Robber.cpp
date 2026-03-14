class Solution {
public:
    // Reucrsion+memoization:
    // int helper(vector<int> &nums,int i,vector<int>&dp){
    //     // Base Case:
    //     if(i>=nums.size()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     // We have two options either Steal or Skip
    //     int steal=nums[i]+helper(nums,i+2,dp);
    //     int skip=helper(nums,i+1,dp);
    //     return dp[i]=max(steal,skip);
    // }
    int rob(vector<int>& nums) {
        // bottom up approach(TABULATION):
        int n=nums.size();
        // vector<int> t(n+1,0);
        // t[i]=max money steal till ith house
        // t[0]=0;
        // t[1]=nums[0];
        // for(int i=2;i<=n;i++){
        //     int steal=nums[i-1]+t[i-2];
        //     int skip=t[i-1];
        //     t[i]=max(skip,steal);
        // }
        // return t[n];
        // int n=nums.size();
        // vector<int> dp(n,-1);
        // return helper(nums,0,dp);
        if(n==1) return nums[0];
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int steal=nums[i] + dp[i-2];
            int skip=dp[i-1];
            dp[i]=max(steal,skip);
        }
        return dp[n-1];
    }
};
