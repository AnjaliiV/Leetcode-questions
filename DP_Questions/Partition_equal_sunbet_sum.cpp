class Solution {
public:
    bool helper(int i,int target,vector<int> &nums, vector<vector<int>> &dp){
        int n=nums.size();
         //we have achieved our target by taking or not taking the elements when target=0
        //  target=sum/2= 11
        //  Ex-[1,5,11,5] :
        // take:1 target=11-1= 10
        // take:5 target=10-5= 5
        // take:11 target=5-11( so we cant take 11) so we'll skip it
        // take:5 target=5-5=0 (one subset formed)
        // so one element remaining 11 that will be our next subset:

        if(target ==0) return true;
        if(i>=n) return false;

        if(dp[i][target] !=-1) return dp[i][target];
        int skip=helper(i+1,target,nums,dp);

        // we can take the element only if nums[i]<=target:
        bool take=false;
        if(nums[i]<=target){
            take=helper(i+1,target-nums[i],nums,dp);
        }

        return dp[i][target]= take || skip;

    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);

        // if sum is odd return false
        if(sum % 2 != 0)  return false;
        
        // The target should be equal to half of the sum;
        int target =  sum/2;

        vector<vector<int>> dp(n,vector<int>(target + 1 ,-1));
        
        return helper(0,target,nums,dp);
    }
};
