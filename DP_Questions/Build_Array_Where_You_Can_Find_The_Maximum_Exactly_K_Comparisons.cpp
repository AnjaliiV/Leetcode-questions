class Solution {
public:
int N,M,K;
int MOD=1e9+7;
    int helper(int ind,int search_count,int maxSoFar){
        // Base Case:
        if(ind==N){
            if(search_count==K){
                return 1;
            }
            else{
                return 0;
            }
        }
        int result=0;
        for(int i=1;i<=M;i++){
        //adding elemet if:
            if(i>maxSoFar){
                result=(result+helper(ind+1,search_count+1,i)) % MOD;
            }
            else{
                result=(result+helper(ind+1,search_count,maxSoFar)) % MOD;
            }
        }
        return result;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        return helper(0,0,0);
    }
};

// class Solution {
// public:
//     int N, M, K;
//     int dp[51][51][101];
//     long long MOD = 1e9+7;

//     long long helper(int idx, int search_count, int maxSoFar) {
//         // Base Case:
//         if (idx == N) {
//             return (search_count == K) ? 1 : 0;
//         }
//         if(dp[idx][search_count][maxSoFar] !=-1) return dp[idx][search_count][maxSoFar];

//         long long result = 0;

//         for (int val = 1; val <= M; val++) {
//             if (val > maxSoFar) {
//                 result = (result + helper(idx + 1, search_count + 1, val)) % MOD;
//             } 
//             else {
//                 result = (result + helper(idx + 1, search_count, maxSoFar)) % MOD;
//             }
//         }
//         return dp[idx][search_count][maxSoFar]=result;
//     }

//     int numOfArrays(int n, int m, int k) {
//         N = n;
//         M = m;
//         K = k;
//         memset(dp,-1,sizeof(dp));
//         return helper(0, 0, 0);
//     }
// };
