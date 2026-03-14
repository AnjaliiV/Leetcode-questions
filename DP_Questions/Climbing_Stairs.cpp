class Solution {
public:
    int climbStairs(int n) {
       vector<int> t(n+1);
       if(n==1||n==2)
           return n;
       
    //    t[0]=0;
       t[1]=1;
       t[2]=2;

       for(int i=3;i<=n;i++){
           t[i]=t[i-1]+t[i-2]; //for 1 and 2 steps
       }
    return t[n];
    } 
};
