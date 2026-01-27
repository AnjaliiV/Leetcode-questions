class Solution {
public:
    void helper(vector<vector<int>>& image, int sr, int sc, int color,int oriclr,int nx[],int ny[],vector<vector<int>>&ans){
        ans[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+nx[i];
            int ncol=sc+ny[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
             && image[nrow][ncol]==oriclr 
             && ans[nrow][ncol]!=color){
                helper(image,nrow,ncol,color,oriclr,nx,ny,ans);
             }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oriclr=image[sr][sc];
        vector<vector<int>> ans=image;
        int nx[]={-1,0,+1,0};
        int ny[]={0,+1,0,-1};
        helper(image,sr,sc,color,oriclr,nx,ny,ans);   
        return ans;
     
    }
};