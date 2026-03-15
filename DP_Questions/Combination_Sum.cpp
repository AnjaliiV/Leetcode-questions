class Solution {
public:
    void helper(int i,vector<int>& candidates, int target,vector<int> &temp,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=candidates.size() || target<0)  return ;

        //PICK
        temp.push_back(candidates[i]);
        helper(i,candidates,target-candidates[i],temp,ans);
        temp.pop_back();
        
        //SKIP:
        helper(i+1,candidates,target,temp,ans);
         
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,candidates,target,temp,ans);
        return ans;

        
    }
};
